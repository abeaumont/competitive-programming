#!/usr/bin/env python3
# Get input/output samples for a contest
import asyncio
import os
import sys

import aiohttp
from bs4 import BeautifulSoup


class BadStatusException(Exception):
    pass


class TaskException(Exception):
    pass


async def process_task(client: aiohttp.ClientSession, name: str, url: str) -> None:
    print('Getting samples for task {}'.format(name))
    async with client.get(url) as response:
        if response.status != 200:
            raise TaskException(
                'Invalid status code {}'.format(response.status))
        soup = BeautifulSoup(await response.text(), 'html.parser')
        sections = soup.find_all('section')
        for section in sections:
            h3 = section.h3.text
            if h3.startswith('Sample'):
                _, io, n = h3.split()
                if io.lower().startswith('in'):
                    fname = '{}-{}.{}'.format(name, n, 'in')
                else:
                    fname = '{}-{}.{}'.format(name, n, 'ans')
                with open(fname, 'w') as f:
                    f.write(section.pre.text.replace('\r\n', '\n'))
    print('Got samples for task {}'.format(name))


async def main(contest: str) -> None:
    async with aiohttp.ClientSession() as client:
        print('Getting samples for contest {}...'.format(contest))
        prefix = 'https://' + contest + '.contest.atcoder.jp'
        url = prefix + '/assignments'
        async with client.get(url) as response:
            if response.status != 200:
                raise BadStatusException(
                    'Bad status for {}: {}'.format(url, response.status))
            soup = BeautifulSoup(await response.text(), 'html.parser')
            table = soup.find_all('tbody')[0]
            tasks = []
            for row in table.find_all('tr'):
                task = row.td.a
                name = task.text.lower()
                url = prefix + task.get('href')
                task = asyncio.ensure_future(process_task(client, name, url))
                tasks.append(task)
            await asyncio.gather(*tasks)


if __name__ == '__main__':
    if len(sys.argv) > 1:
        contest = sys.argv[1]
    else:
        contest = os.path.basename(os.path.abspath(os.curdir))
    asyncio.get_event_loop().run_until_complete(main(contest))
