/*
 * Copyright (c) 2022, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARED_CDS_CDS_GLOBALS_HPP
#define SHARED_CDS_CDS_GLOBALS_HPP

#include "runtime/globals_shared.hpp"

//
// Defines all globals flags used by CDS.
//

#define CDS_FLAGS(develop,                                                  \
                  develop_pd,                                               \
                  product,                                                  \
                  product_pd,                                               \
                  notproduct,                                               \
                  range,                                                    \
                  constraint)                                               \
  /* Shared spaces */                                                       \
                                                                            \
  product(bool, VerifySharedSpaces, false,                                  \
          "Verify integrity of shared spaces")                              \
                                                                            \
  product(bool, RecordDynamicDumpInfo, false,                               \
          "Record class info for jcmd VM.cds dynamic_dump")                 \
                                                                            \
  product(bool, AutoCreateSharedArchive, false,                             \
          "Create shared archive at exit if cds mapping failed")            \
                                                                            \
  product(bool, PrintSharedArchiveAndExit, false,                           \
          "Print shared archive file contents")                             \
                                                                            \
  product(bool, PrintSharedDictionary, false,                               \
          "If PrintSharedArchiveAndExit is true, also print the shared "    \
          "dictionary")                                                     \
                                                                            \
  product(size_t, SharedBaseAddress, LP64_ONLY(32*G)                        \
          NOT_LP64(LINUX_ONLY(2*G) NOT_LINUX(0)),                           \
          "Address to allocate shared memory region for class data")        \
          range(0, SIZE_MAX)                                                \
                                                                            \
  product(ccstr, SharedArchiveConfigFile, NULL,                             \
          "Data to add to the CDS archive file")                            \
                                                                            \
  product(uint, SharedSymbolTableBucketSize, 4,                             \
          "Average number of symbols per bucket in shared table")           \
          range(2, 246)                                                     \
                                                                            \
  product(bool, AllowArchivingWithJavaAgent, false, DIAGNOSTIC,             \
          "Allow Java agent to be run with CDS dumping")                    \
                                                                            \
  product(ccstr, DumpLoadedClassList, NULL,                                 \
          "Dump the names all loaded classes, that could be stored into "   \
          "the CDS archive, in the specified file")                         \
                                                                            \
  product(ccstr, SharedClassListFile, NULL,                                 \
          "Override the default CDS class list")                            \
                                                                            \
  product(ccstr, SharedArchiveFile, NULL,                                   \
          "Override the default location of the CDS archive file")          \
                                                                            \
  product(ccstr, ArchiveClassesAtExit, NULL,                                \
          "The path and name of the dynamic archive file")                  \
                                                                            \
  product(ccstr, ExtraSharedClassListFile, NULL,                            \
          "Extra classlist for building the CDS archive file")              \
                                                                            \
  product(int, ArchiveRelocationMode, 0, DIAGNOSTIC,                        \
           "(0) first map at preferred address, and if "                    \
           "unsuccessful, map at alternative address (default); "           \
           "(1) always map at alternative address; "                        \
           "(2) always map at preferred address, and if unsuccessful, "     \
           "do not map the archive")                                        \
           range(0, 2)                                                      \
// end of CDS_FLAGS

DECLARE_FLAGS(CDS_FLAGS)

#endif // SHARED_CDS_CDS_GLOBALS_HPP
