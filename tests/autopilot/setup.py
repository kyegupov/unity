#!/usr/bin/python

from distutils.core import setup
from setuptools import find_packages

setup(
    name='autopilot',
    version='1.0',
    description='Unity test driver automation script',
    author='Alex Launi',
    author_email='alex.launi@canonical.com',
    url='https://launchpad.net/unity',
    license='GPLv3',
    packages=find_packages(),
    scripts=['bin/run_autopilot'],
)
