from math import e, log

def log_n(n):
    return e ** n

def sqrt_n(n):
    return n ** 2

def n(n):
    return n

def n_log_n(n):
    return n / log(n)

def n_2(n):
    return n ** (1 / 2)

def n_3(n):
    return n ** (1 / 3)

def two_n(n):
    return log(n, 2)

def n_factorial(n):
    return e * (n ** (n + 1 / 2)) * (e ** (-n))

time = {
    'second': 1,
    'minute': 60,
    'hour': 3600,
    'day': 3600 * 24,
    'month': 3600 * 24 * 30,
    'year': 3600 * 24 * 30 * 365,
    'century': 3600 * 24 * 30 * 365 * 10
}

for key in time.keys():
    print('Function log(n) can have max n = {} for 1 {}'.format(log_n(time[key]), key))

