from nose.tools import *
from stats.statistics import *

def test_nose():
    assert True

def test_exists():
    s = Stats()

def test_init():
    s = Stats()
    assert s.num_entries == 0
    assert s.sum == 0

def test_fill():
    s = Stats()
    s.fill(5)
    s.fill(7)
    s.fill(11)
    assert s.sum == 23
    assert s.num_entries == 3

@raises(TypeError)
def test_fill_nonsense():
    s = Stats()
    s.fill('hello')
