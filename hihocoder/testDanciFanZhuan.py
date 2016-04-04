__author__ = 'celhipc'

import unittest

from danCiFanZhuan import reWords, reverseStr

class MyTest(unittest.TestCase):

    def test_reverse(self):
        self.assertEqual(reverseStr('you'), 'uoy')

    def wetest_reWords(self):
        self.assertEqual(reWords("we are good"), "good are we")
        self.assertEqual(reWords('  you are good  ', '  good are you   '))
