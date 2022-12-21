#!/usr/bin/env python
# Copyright 2016 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
"""Takes a timestamp and writes it in as readable text to a .h file."""

import argparse
import datetime
import os
import sys


def main():
  argument_parser = argparse.ArgumentParser()
  argument_parser.add_argument('output_file', help='The file to write to')
  argument_parser.add_argument('timestamp')
  args = argument_parser.parse_args()

  date = datetime.datetime.utcfromtimestamp(int(args.timestamp))
  output = ('// Generated by //build/write_build_date_header.py\n'
           '#ifndef BUILD_DATE\n'
           '#define BUILD_DATE "{:%b %d %Y %H:%M:%S}"\n'
           '#endif // BUILD_DATE\n'.format(date))

  current_contents = ''
  if os.path.isfile(args.output_file):
    with open(args.output_file, 'r') as current_file:
      current_contents = current_file.read()

  if current_contents != output:
    with open(args.output_file, 'w') as output_file:
      output_file.write(output)
  return 0


if __name__ == '__main__':
  sys.exit(main())
