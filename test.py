#!/usr/bin/env python3
import collections
import os
import os.path
import shutil
import subprocess
import sys
import re

languages = [
    'arr', 'c', 'cc', 'cr', 'd', 'hx', 'factor', 'go', 'jl', 'js', 'lid',
    'lisp', 'ml', 'moon', 'nim', 'ooc', 'pi', 'pony', 'py', 'rb', 'rkt', 'rs',
    'sage', 'sml', 'stanza', 'sh', 'wren', 'zig'
]


class ansicolors:
    OK = '\033[92m'
    FAIL = '\033[91m'
    WARN = '\033[93m'
    ENDC = '\033[0m'


def print_fail(message=''):
    print(ansicolors.FAIL + '[FAIL] ' + ansicolors.ENDC + message)


def print_ok(message=''):
    print(ansicolors.OK + '[OK] ' + ansicolors.ENDC + message)


def print_warn(message=''):
    print(ansicolors.WARN + '[WARN] ' + ansicolors.ENDC + message)


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

    def run(self, generate=False):
        ok = True
        for test in self.tests:
            try:
                if generate:
                    print('Generating answer for {} with {}...'
                          .format(test, self.code), end='')
                else:
                    print('Checking {} for {}... '.format(self.code, test),
                          end='')
                cmd = self.run_command(test)
                output = subprocess.check_output(cmd, stderr=subprocess.STDOUT,
                                                 shell=True).decode('utf-8')
                ans = os.path.splitext(test)[0] + '.ans'
                if generate:
                    with open(ans, 'w') as f:
                        f.write(output)
                    print_ok()
                else:
                    with open(ans) as f:
                        output2 = f.read()
                        if output == output2:
                            print_ok()
                        else:
                            print_fail()
                            ok = False
            except subprocess.CalledProcessError as e:
                print_fail(e.output.decode('utf-8'))
                ok = False
            except Exception as e:
                print_fail(str(e))
                ok = False
        if not ok:
            raise


class c(solution):
    @property
    def target(self):
        return self._target() + '-c'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'cc {} -o {} -O2 -std=c11'.format(self.code, self.target)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)


class arr(solution):
    # FIXME: Pyret solutions are not checked
    def run(self, generate=False):
        print_warn('Pyret solutions are disabled')

    def build(self):
        pass

    def run_command(self, test):
        pass

    def clean(self):
        pass


class cc(solution):
    @property
    def target(self):
        return self._target() + '-cc'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'c++ {} -o {} -O2 -std=c++17'.format(self.code, self.target)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)


class cr(solution):
    # FIXME: Crystal solutions are not checked
    def run(self, generate=False):
        print_warn('Crystal solutions are disabled')
        return True

    @property
    def target(self):
        return self._target() + '-cr'

    def build(self):
        return
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'crystal build {} -o {}'.format(self.code, self.target)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        return True
        os.remove(self.target)


class d(solution):
    @property
    def target(self):
        return self._target() + '-d'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'dmd {} -of={} -O'.format(self.code, self.target)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)


class hx(solution):
    @property
    def target(self):
        return self._target() + '-hx'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            target = os.path.basename(self.target)
            klass = os.path.basename(self._target())
            dir, code = os.path.split(self.code)
            cmd = 'cd {} && haxe -python {} -main {} {}'\
                .format(dir, target, klass, code)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return 'pypy3 {} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)


class factor(solution):
    def build(self):
        pass

    def run_command(self, test):
        return './{} < {}'.format(self.code, test)

    def clean(self):
        pass


class go(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'go run {} < {}'.format(self.code, test)

    def clean(self):
        pass


class jl(solution):
    def build(self):
        pass

    def run_command(self, test):
        return './{} < {}'.format(self.code, test)

    def clean(self):
        pass


class js(solution):
    def build(self):
        pass

    def run_command(self, test):
        return './{} < {}'.format(self.code, test)

    def clean(self):
        pass


class lid(solution):
    """OpenDylan solutions"""

    def build(self):
        try:
            print('Building {}...'.format(self._target() + '-dylan'), end='')
            cmd = 'dylan-compiler -build {}'.format(self.code)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        root = os.getenv('OPEN_DYLAN_USER_ROOT', '_build')
        target = os.path.basename(self._target())
        return '{} < {}'.format(os.path.join(root, 'bin', target), test)

    def clean(self):
        root = os.getenv('OPEN_DYLAN_USER_ROOT',
                         os.path.join(os.path.dirname(self.code), '_build'))
        shutil.rmtree(root, True)


class lisp(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'sbcl --script {} < {}'.format(self.code, test)

    def clean(self):
        pass


class ml(solution):
    @property
    def target(self):
        return self._target() + '.native'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'corebuild {}'.format(self.target[2:])
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return './{} < {}'.format(os.path.basename(self.target), test)

    def clean(self):
        os.remove(os.path.basename(self.target))
        shutil.rmtree('_build', True)


class moon(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'moon {} < {}'.format(self.code, test)

    def clean(self):
        pass


class nim(solution):
    @property
    def target(self):
        return self._target() + '-nim'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'nim c -o:{} -d:release {}'.format(self.target, self.code)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)
        dirname = os.path.dirname(self.code)
        shutil.rmtree(os.path.join(dirname, 'nimcache'), True)


class ooc(solution):
    @property
    def target(self):
        return self._target() + '-ooc'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            target = os.path.basename(self.target)
            dir, code = os.path.split(self.code)
            cmd = 'cd {} && rock {} -O3 -o={}'\
                .format(dir, code, target)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)
        dirname = os.path.dirname(self.code)
        shutil.rmtree(os.path.join(dirname, 'rock_tmp'), True)
        shutil.rmtree(os.path.join(dirname, '.libs'), True)


class pi(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'picat {} < {}'.format(self.code, test)

    def clean(self):
        pass


class pony(solution):
    @property
    def target(self):
        return self._target()

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'cd {} && ponyc'.format(os.path.dirname(self.code))
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)


class py(solution):
    def build(self):
        pass

    def run_command(self, test):
        return './{} < {}'.format(self.code, test)

    def clean(self):
        pass


class rb(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'ruby {} < {}'.format(self.code, test)

    def clean(self):
        pass


class rkt(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'racket {} < {}'.format(self.code, test)

    def clean(self):
        pass


class rs(solution):
    @property
    def target(self):
        return self._target() + '-rs'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'rustc {} -o {} -O'.format(self.code, self.target)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)


class sage(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'python {}.py < {}'.format(self.code, test)

    def clean(self):
        pass


class sml(solution):
    @property
    def target(self):
        return self._target() + '-sml'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'mlton -output {} {}'.format(self.target, self.code)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)


class stanza(solution):
    @property
    def target(self):
        return self._target() + '-stanza'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'stanza {} -o {} -optimize'.format(self.code, self.target)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {}'.format(self.target, test)

    def clean(self):
        os.remove(self.target)


class sh(solution):
    def build(self):
        pass

    def run_command(self, test):
        return './{} < {}'.format(self.code, test)

    def clean(self):
        pass


class wren(solution):
    def build(self):
        pass

    def run_command(self, test):
        return 'cat {}|./{}'.format(test, self.code)

    def clean(self):
        pass


class zig(solution):
    @property
    def target(self):
        return self._target() + '-zig'

    def build(self):
        try:
            print('Building {}... '.format(self.target), end='')
            cmd = 'zig build-exe {} --output {}'.format(self.code, self.target)
            subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True)
            print_ok()
        except subprocess.CalledProcessError as e:
            print_fail(e.output.decode('utf-8'))
            raise e
        except Exception as e:
            print_fail(str(e))
            raise e

    def run_command(self, test):
        return '{} < {} 2>&1'.format(self.target, test)

    def clean(self):
        os.remove(self.target)
        dirname = os.path.dirname(self.code)
        shutil.rmtree(os.path.join(dirname, 'zig-cache'), True)


def check_code(solutions):
    filtered = []
    ok = True
    for code, tests in solutions.items():
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
        except Exception:
            ok = False
    return solutions, ok


def run_solutions(solutions, generate):
    ok = True
    for solution in solutions:
        try:
            solution.run(generate)
        except Exception:
            ok = False
    return ok


def clean_solutions(solutions):
    print('Cleaning solutions...')
    ok = True
    for solution in solutions:
        try:
            solution.clean()
        except Exception:
            ok = False
    return ok


def check_solutions(solutions, generate):
    """If generate is true, generate the answers instead of cheking them"""
    ok = True
    solutions, ok2 = check_code(solutions)
    ok = ok and ok2
    solutions, ok2 = build_solutions(solutions)
    ok = ok and ok2
    ok2 = run_solutions(solutions, generate)
    ok = ok and ok2
    ok2 = clean_solutions(solutions)
    return ok and ok2, len(solutions)


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
    s = [(k, solutions[k]) for k in sorted(solutions.keys())]
    return collections.OrderedDict(s)


def main(generate):
    """Test that all the solutions build and provide proper outputs"""
    solutions = get_solutions()
    ok, s = check_solutions(solutions, generate)
    if generate:
        print('Generated {} solutions for {} problems...'
              .format(s, len(solutions)))
    else:
        print('Checked {} solutions for {} problems...'
              .format(s, len(solutions)))
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main(len(sys.argv) > 1))
