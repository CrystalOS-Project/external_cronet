#!/usr/bin/env python3
# Copyright 2017 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Generator for a C++ file mapping known trust anchors to histogram values.

The generated structure will be sorted by SHA-256 hash of the
subjectPublicKeyInfo, to allow efficient lookup. The value '0' is reserved
as a sentinel value to indicate 'not found'.
"""

import json
import os.path
import platform
import sys
from subprocess import call

THIS_DIR = os.path.dirname(os.path.abspath(__file__))
SRC_DIR = os.path.normpath(os.path.join(THIS_DIR, '..', '..', '..', '..'))

ROOT_CERT_LIST_PATH = 'net/cert/root_cert_list_generated.h'
ROOT_STORE_FILE_PATH = 'net/data/ssl/root_stores/root_stores.json'

LICENSE_AND_HEADER = b"""\
// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// This file is generated by
// net/data/ssl/root_stores/update_root_stores.py
// It's formatted by clang-format using Chromium coding style:
//   clang-format -i -style=chromium filename
// DO NOT EDIT!
//

#ifndef NET_CERT_ROOT_CERT_LIST_GENERATED_H_
#define NET_CERT_ROOT_CERT_LIST_GENERATED_H_

#include <stdint.h>

namespace net {

namespace {

// The list of known trust anchors, sorted by sha256_spki_hash.
const struct RootCertData {
  // The SHA-256 hash of the associated certificate's subjectPublicKeyInfo.
  unsigned char sha256_spki_hash[32];

  // A value suitable for histograms using the NetTrustAnchors enum.
  int16_t histogram_id : 15;

  // If true, indicates the CA is considered a "Legacy" CA, formerly trusted
  // or not yet trusted.
  bool legacy_ca : 1;
} kRootCerts[] = {
"""

FOOTER = b"""\

};

}  // namespace

}  // namespace net

#endif  // NET_CERT_ROOT_CERT_LIST_GENERATED_H_
"""

def _GetInputFile(src_relative_file_path):
  """Converts a src/-relative path into a path that can be opened."""
  return os.path.join(SRC_DIR, src_relative_file_path)

def ClangFormat(filename):
  formatter = 'clang-format'
  if sys.platform == 'win32':
    formatter += '.bat'
  return call([formatter, '-i', '-style=chromium', filename])

def main():
  if len(sys.argv) > 1:
    print >>sys.stderr, 'No arguments expected!'
    sys.stderr.write(__doc__)
    return 1

  with open(_GetInputFile(ROOT_STORE_FILE_PATH), 'r') as root_store_file:
    root_stores = json.load(root_store_file)

  with open(_GetInputFile(ROOT_CERT_LIST_PATH), 'wb') as header_file:
    header_file.write(LICENSE_AND_HEADER)
    for spki, data in sorted(root_stores['spkis'].items()):
      cpp_str = ''.join('0x{:02X}, '.format(x) for x in bytearray.fromhex(spki))
      log_id = int(data['id'])
      legacy = 'legacy' in data and data['legacy']
      header_file.write(
          ('{ { %s },\n%d, %s }, ' %
           (cpp_str, log_id, "true" if legacy else "false")).encode('utf-8'))

    header_file.write(FOOTER)

  return ClangFormat(_GetInputFile(ROOT_CERT_LIST_PATH))

if __name__ == '__main__':
  sys.exit(main())
