import re
import os
import os.path
import subprocess
import sys

languages = ['cc', 'py']


class ansicolors:
    OK = '\033[92m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'


def print_fail(message=''):
    print ansicolors.FAIL + '[FAIL] ' + ansicolors.ENDC + message


def print_ok(message=''):
    print ansicolors.OK + '[OK] ' + ansicolors.ENDC + message


class solution(object):
    def __init__(self, code, tests):
        self.code = code
        self.tests = tests

    def __repr__(self):
        return '{}: {}'.format(self.code, ', '.join(self.tests))

    def _target(self):
        return os.path.splitext(self.code)[0]

    def build(self):
        raise NotImplementedError

    def run_command(self, test):
        raise NotImplementedError

    def clean(self):
        raise NotImplementedError

    def run(self):
        ok = True
        target = self._target()
        for test in self.tests:
            try:
                print 'Checking {} for {}... '.format(target, test),
                cmd = self.run_command(test)
                output = subprocess.check_output(cmd, stderr=subprocess.STDOUT,
                                                 shell=True)
                ans = os.path.splitext(test)[0] + '.ans'
                with open(ans) as f:
                    output2 = f.read()
                    if output == output2:
                        print_ok()
                    else:
                        print_fail()
                        ok = False
            except subprocess.CalledProcessError as e:
                print_fail(e.output)
                ok = False
            except Exception as e:
                print_fail(str(e))
                ok = False
        if not ok:
            raise


class cc(solution):
    def build(self):
        target = self._target()
        try:
            print 'Building {}... '.format(target),
            cmd = 'g++ {} -O2 -o {}'.format(self.code, target)
            output = subprocess.check_output(cmd, stderr=subprocess.STDOUT,
                                             shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output)
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return './{} < {}'.format(self._target(), test)

    def clean(self):
        target = self._target()
        os.remove(target)


class py(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'python2 {} < {}'.format(self.code, test)

    def clean(self):
        pass


def check_code(solutions):
    filtered = []
    ok = True
    for code, tests in solutions.iteritems():
        names = []
        for lang in languages:
            name = code + '.' + lang
            if os.path.exists(name):
                names.append((lang, name))
        if len(names) == 0:
            fmt = 'No solution file exists for the following test files: {}.'
            print_fail(fmt.format(', '.join(tests)))
            ok = False
        else:
            for lang, name in names:
                filtered.append(globals()[lang](name, tests))
    return filtered, ok


def build_solutions(solutions):
    filtered = []
    ok = True
    for solution in solutions:
        try:
            solution.build()
            filtered.append(solution)
        except:
            ok = False
    return solutions, ok


def run_solutions(solutions):
    ok = True
    for solution in solutions:
        try:
            solution.run()
        except:
            ok = False
    return ok


def clean_solutions(solutions):
    print 'Cleaning solutions...'
    ok = True
    for solution in solutions:
        try:
            solution.clean()
        except:
            ok = False
    return ok


def check_solutions(solutions):
    ok = True
    solutions, ok2 = check_code(solutions)
    ok = ok and ok2
    solutions, ok2 = build_solutions(solutions)
    ok = ok and ok2
    ok2 = run_solutions(solutions)
    ok = ok and ok2
    ok2 = clean_solutions(solutions)
    return ok and ok2


def get_solutions(root='.'):
    """Get the expected solutions and their related input files"""
    solutions = {}
    for root, _, files in os.walk(root):
        for f in files:
            m = re.search('(.*)-\d.in$', f)
            if m is None:
                continue
            code = os.path.join(root, m.group(1))
            test = os.path.join(root, f)
            if code in solutions:
                solutions[code].append(test)
            else:
                solutions[code] = [test]
    return solutions


def main():
    """Test that all the solutions build and provide proper outputs"""
    ok = check_solutions(get_solutions())
    return 0 if ok else 1

if __name__ == '__main__':
    sys.exit(main())
