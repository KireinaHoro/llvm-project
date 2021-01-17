//===--- LoopHint.h - Types for LoopHint ------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_PARSE_HLS_H
#define LLVM_CLANG_PARSE_HLS_H

#include "clang/Basic/IdentifierTable.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Sema/Ownership.h"
#include "clang/Sema/ParsedAttr.h"

namespace clang {

/// Directives for HLS-related pragmas.
struct HLS {
  // Source range of the directive.
  SourceRange Range;
  // Identifier corresponding to the name of the pragma.
  // "HLS" in #pragma HLS unroll
  IdentifierLoc *PragmaNameLoc;
  // Name of the HLS option.
  // "unroll" in #pragma HLS unroll
  IdentifierLoc *OptionLoc;
  // Identifier for the hint state argument.  If null, then the state is
  // default value such as for "#pragma unroll".
  IdentifierLoc *StateLoc;
  // Expression for the hint argument if it exists, null otherwise.
  Expr *ValueExpr;

  HLS()
      : PragmaNameLoc(nullptr), OptionLoc(nullptr), StateLoc(nullptr),
        ValueExpr(nullptr) {}
};

} // end namespace clang

#endif // LLVM_CLANG_PARSE_HLS_H
