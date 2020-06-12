#!/usr/bin/env python2

"""
TEST USING THE FOLLOWING

python3 setup.py install --install-lib ./installed

"""
from distutils.core import setup, Extension


if __name__ == '__main__':
         
    setup(
          # Some metadata
          name='Test',
          version='0.9',
          description='Test example',
          author='Pasquale Lafiosca',
          url='',
          # The name of the main python package goes here
          packages=['mypkg'],                                       
          # mypkg.test is how you will call it from python, mypkg/test.cpp is the relative path to the source code
          ext_modules=[Extension('mypkg.test', ['mypkg/test.cpp'])], 
         )
