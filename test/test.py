#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import StringFilter

def test_rabbit_and_turtle() -> None:
    sf = StringFilter.StringFilter(key='rabbit and turtle')
    assert sf.is_valid(sentence='rabbit vs turtle')
    assert not sf.is_valid(sentence='Sea turtles were released to the ocean.')


def test_null_str() -> None:
    sf = StringFilter.StringFilter('')
    assert sf.is_valid(
        'Buffalo buffalo Buffalo buffalo buffalo buffalo Buffalo buffalo.')

    sf = StringFilter.StringFilter('buffalo')
    assert not sf.is_valid('')
