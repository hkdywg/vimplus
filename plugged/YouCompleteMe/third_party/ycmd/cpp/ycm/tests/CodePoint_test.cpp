// Copyright (C) 2018 ycmd contributors
//
// This file is part of ycmd.
//
// ycmd is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// ycmd is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with ycmd.  If not, see <http://www.gnu.org/licenses/>.

#include "CodePoint.h"
#include "CodePointRepository.h"
#include "TestUtils.h"

#include <array>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::TestWithParam;
using ::testing::ValuesIn;

namespace YouCompleteMe {

struct TextCodePointPair {
  const char* text;
  CodePointTuple code_point_tuple;
};


std::ostream& operator<<( std::ostream& os,
                          const TextCodePointPair &pair ) {
  os << "{ " << PrintToString( pair.text ) << ", "
             << PrintToString( pair.code_point_tuple ) << " }";
  return os;
}


class CodePointTest : public TestWithParam< TextCodePointPair > {
protected:
  CodePointTest()
    : repo_( CodePointRepository::Instance() ) {
  }

  virtual void SetUp() {
    repo_.ClearCodePoints();
    pair_ = GetParam();
  }

  CodePointRepository &repo_;
  TextCodePointPair pair_;
};


TEST_P( CodePointTest, PropertiesAreCorrect ) {
  EXPECT_THAT( CodePoint( pair_.text ),
               IsCodePointWithProperties( pair_.code_point_tuple ) );
}


// Tests mostly based on the table
// http://www.unicode.org/reports/tr29/#Grapheme_Cluster_Break_Property_Values
const TextCodePointPair tests[] = {
  { "\r", { "\r", "\r", "\r", false, false, false, BreakProperty::CR } },

  { "\n", { "\n", "\n", "\n", false, false, false, BreakProperty::LF } },

  { "\t", { "\t", "\t", "\t", false, false, false, BreakProperty::CONTROL } },
  // Line separator
  { "\xe2\x80\xa8", { "\xe2\x80\xa8", "\xe2\x80\xa8", "\xe2\x80\xa8",
                      false, false, false, BreakProperty::CONTROL } },
  // Paragraph separator
  { "\xe2\x80\xa9", { "\xe2\x80\xa9", "\xe2\x80\xa9", "\xe2\x80\xa9",
                      false, false, false, BreakProperty::CONTROL } },
  // Zero-width space
  { "???", { "???", "???", "???", false, false, false,
                BreakProperty::CONTROL } },

  // Combining grave accent
  { "??", { "??", "??", "??", false, false, false, BreakProperty::EXTEND } },
  // Bengali vowel sign Aa
  { "???", { "???", "???", "???", false, false, false, BreakProperty::EXTEND } },
  // Zero-width non-joiner
  { "???", { "???", "???", "???", false, false, false,
                BreakProperty::EXTEND } },
  // Combining cyrillic millions sign
  { "??", { "??", "??", "??", false, false, false, BreakProperty::EXTEND } },

  // Zero-width joiner
  { "???", { "???", "???", "???", false, false, false,
                BreakProperty::ZWJ } },

  // Regional indicator symbol letter b
  { "????", { "????", "????", "????", false, false, false,
            BreakProperty::REGIONAL_INDICATOR } },

  // Arabic number sign
  { "??", { "??", "??", "??", false, false, false, BreakProperty::PREPEND } },

  // Thai character Sara Am
  { "???", { "???", "???", "???", true, false, false, BreakProperty::SPACINGMARK } },
  // Lao vowel sign Am
  { "???", { "???", "???", "???", true, false, false, BreakProperty::SPACINGMARK } },

  // Hangul Choseong Kiyeok
  { "???", { "???", "???", "???", true, false, false, BreakProperty::L } },
  // Hangul Choseong Filler
  { "???", { "???", "???", "???", true, false, false, BreakProperty::L } },
  // Hangul Choseong Tikeut-mieum
  { "???", { "???", "???", "???", true, false, false, BreakProperty::L } },
  // Hangul Choseong Ssangyeorinhieuh
  { "???", { "???", "???", "???", true, false, false, BreakProperty::L } },

  // Hangul Jungseong Filler
  { "???", { "???", "???", "???", true, false, false, BreakProperty::V } },
  // Hangul Jungseong Ssangaraea
  { "???", { "???", "???", "???", true, false, false, BreakProperty::V } },
  // Hangul Jungseong O-yeo
  { "???", { "???", "???", "???", true, false, false, BreakProperty::V } },
  // Hangul Jungseong Araea-e
  { "???", { "???", "???", "???", true, false, false, BreakProperty::V } },

  // Hangul Jongseong Kiyeok
  { "???", { "???", "???", "???", true, false, false, BreakProperty::T } },
  // Hangul Jongseong Yeorinhieuh
  { "???", { "???", "???", "???", true, false, false, BreakProperty::T } },
  // Hangul Jongseong Nieun-rieul
  { "???", { "???", "???", "???", true, false, false, BreakProperty::T } },
  // Hangul Jongseong Phieuph-thieuth
  { "???", { "???", "???", "???", true, false, false, BreakProperty::T } },

  // Hangul syllable Ga
  { "???", { "??????", "??????", "??????", true, false, false, BreakProperty::LV } },
  // Hangul syllable Gae
  { "???", { "??????", "??????", "??????", true, false, false, BreakProperty::LV } },
  // Hangul syllable Gya
  { "???", { "??????", "??????", "??????", true, false, false, BreakProperty::LV } },

  // Hangul syllable Gag
  { "???", { "?????????", "?????????", "?????????", true, false, false, BreakProperty::LVT } },
  // Hangul syllable Gagg
  { "???", { "?????????", "?????????", "?????????", true, false, false, BreakProperty::LVT } },
  // Hangul syllable Gags
  { "???", { "?????????", "?????????", "?????????", true, false, false, BreakProperty::LVT } },
  // Hangul syllable Gan
  { "???", { "?????????", "?????????", "?????????", true, false, false, BreakProperty::LVT } },

  // Copyright sign
  { "??", { "??", "??", "??", false, false, false, BreakProperty::EXTPICT } },

  // Characters with none of the above break properties.

  // One byte characters
  // NOTE: there are no Unicode letters coded with one byte (i.e. ASCII letters)
  // without a lowercase or uppercase version.
  { "r", { "r", "r", "R", true,  false, false, BreakProperty::OTHER } },
  { "R", { "R", "r", "r", true,  false, true,  BreakProperty::OTHER } },
  { "'", { "'", "'", "'", false, true,  false, BreakProperty::OTHER } },
  { "=", { "=", "=", "=", false, false, false, BreakProperty::OTHER } },
  // Two bytes characters
  { "??", { "e??", "e??", "E??", true,  false, false, BreakProperty::OTHER } },
  { "??", { "E??", "e??", "e??", true,  false, true,  BreakProperty::OTHER } },
  { "??", { "??", "??", "??", true,  false, false, BreakProperty::OTHER } },
  { "??", { "??", "??", "??", false, true,  false, BreakProperty::OTHER } },
  { "??", { "??", "??", "??", false, false, false, BreakProperty::OTHER } },
  // Three bytes characters
  { "???", { "???", "???", "??", true,  false, false, BreakProperty::OTHER } },
  { "???", { "???", "??", "??", true,  false, true,  BreakProperty::OTHER } },
  { "???", { "???", "???", "???", true, false, false, BreakProperty::OTHER } },
  { "???", { "???", "???", "???", false, true,  false, BreakProperty::OTHER } },
  { "???", { "???", "???", "???", false, false, false, BreakProperty::OTHER } },
  // Four bytes characters
  { "????", { "????", "????", "????", true,  false, false, BreakProperty::OTHER } },
  { "????", { "????", "????", "????", true,  false, true,  BreakProperty::OTHER } },
  { "????", { "????", "????", "????", true,  false, false, BreakProperty::OTHER } },
  { "????", { "????", "????", "????", false, true,  false, BreakProperty::OTHER } },
  { "????", { "????", "????", "????", false, false, false, BreakProperty::OTHER } },
};


INSTANTIATE_TEST_CASE_P( UnicodeTest, CodePointTest, ValuesIn( tests ) );

} // namespace YouCompleteMe
