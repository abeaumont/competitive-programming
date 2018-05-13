#!/usr/bin/env python3
# Get input/output samples for a contest
import os
import sys

import requests

from bs4 import BeautifulSoup


class TaskException(Exception):
    pass


def get_task(name: str, url: str) -> None:
    response = requests.get(url)
    if response.status_code != requests.codes.ok:
        raise TaskException('Invalid status code {}'.format(response.status_code))
    soup = BeautifulSoup(response.text, 'html.parser')
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


def main(contest: str) -> int:
    print('Getting samples for contest {}...'.format(contest))
    prefix = 'https://' + contest + '.contest.atcoder.jp'
    url = prefix + '/assignments'
    response = requests.get(url)  # pyre-ignore[18]
    if response.status_code != requests.codes.ok:
        print('Something went wrong on request to {}: {}'.format(
            url, response.status_code), sys.stderr)
        return -1
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find_all('tbody')[0]
    for row in table.find_all('tr'):
        task = row.td.a
        name = task.text.lower()
        url = prefix + task.get('href')
        try:
            print('Getting samples for task {}'.format(name))
            get_task(name, url)
            print('Got samples for task {}'.format(name))
        except Exception as e:
            print('Error getting task {} from {}: {}'.format(
                name, url, e), sys.stderr)
            return -2
    return 0


if __name__ == '__main__':
    if len(sys.argv) > 1:
        contest = sys.argv[1]
    else:
        contest = os.path.basename(os.path.abspath(os.curdir))
    sys.exit(main(contest))
