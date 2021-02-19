// Copyright (c) 2021, k-noya
// Distributed under the BSD 3-Clause License.
// See accompanying file LICENSE
#include "mh2c/hpack/huffman_code.h"

namespace mh2c {

namespace huffman {

const encode_table_t encode_table{
    {0u, {0x1ff8, 13u}},      {1u, {0x7fffd8, 23u}},
    {2u, {0xfffffe2, 28u}},   {3u, {0xfffffe3, 28u}},
    {4u, {0xfffffe4, 28u}},   {5u, {0xfffffe5, 28u}},
    {6u, {0xfffffe6, 28u}},   {7u, {0xfffffe7, 28u}},
    {8u, {0xfffffe8, 28u}},   {9u, {0xffffea, 24u}},
    {10u, {0x3ffffffc, 30u}}, {11u, {0xfffffe9, 28u}},
    {12u, {0xfffffea, 28u}},  {13u, {0x3ffffffd, 30u}},
    {14u, {0xfffffeb, 28u}},  {15u, {0xfffffec, 28u}},
    {16u, {0xfffffed, 28u}},  {17u, {0xfffffee, 28u}},
    {18u, {0xfffffef, 28u}},  {19u, {0xffffff0, 28u}},
    {20u, {0xffffff1, 28u}},  {21u, {0xffffff2, 28u}},
    {22u, {0x3ffffffe, 30u}}, {23u, {0xffffff3, 28u}},
    {24u, {0xffffff4, 28u}},  {25u, {0xffffff5, 28u}},
    {26u, {0xffffff6, 28u}},  {27u, {0xffffff7, 28u}},
    {28u, {0xffffff8, 28u}},  {29u, {0xffffff9, 28u}},
    {30u, {0xffffffa, 28u}},  {31u, {0xffffffb, 28u}},
    {31u, {0xffffffb, 28u}},  {32u, {0x14, 6u}},
    {33u, {0x3f8, 10u}},      {34u, {0x3f9, 10u}},
    {35u, {0xffa, 12u}},      {36u, {0x1ff9, 13u}},
    {37u, {0x15, 6u}},        {38u, {0xf8, 8u}},
    {39u, {0x7fa, 11u}},      {40u, {0x3fa, 10u}},
    {41u, {0x3fb, 10u}},      {42u, {0xf9, 8u}},
    {43u, {0x7fb, 11u}},      {44u, {0xfa, 8u}},
    {45u, {0x16, 6u}},        {46u, {0x17, 6u}},
    {47u, {0x18, 6u}},        {48u, {0x0, 5u}},
    {49u, {0x1, 5u}},         {50u, {0x2, 5u}},
    {51u, {0x19, 6u}},        {52u, {0x1a, 6u}},
    {53u, {0x1b, 6u}},        {54u, {0x1c, 6u}},
    {55u, {0x1d, 6u}},        {56u, {0x1e, 6u}},
    {57u, {0x1f, 6u}},        {58u, {0x5c, 7u}},
    {59u, {0xfb, 8u}},        {60u, {0x7ffc, 15u}},
    {61u, {0x20, 6u}},        {62u, {0xffb, 12u}},
    {63u, {0x3fc, 10u}},      {64u, {0x1ffa, 13u}},
    {65u, {0x21, 6u}},        {66u, {0x5d, 7u}},
    {67u, {0x5e, 7u}},        {68u, {0x5f, 7u}},
    {69u, {0x60, 7u}},        {70u, {0x61, 7u}},
    {71u, {0x62, 7u}},        {72u, {0x63, 7u}},
    {73u, {0x64, 7u}},        {74u, {0x65, 7u}},
    {75u, {0x66, 7u}},        {76u, {0x67, 7u}},
    {77u, {0x68, 7u}},        {78u, {0x69, 7u}},
    {79u, {0x6a, 7u}},        {80u, {0x6b, 7u}},
    {81u, {0x6c, 7u}},        {82u, {0x6d, 7u}},
    {83u, {0x6e, 7u}},        {84u, {0x6f, 7u}},
    {85u, {0x70, 7u}},        {86u, {0x71, 7u}},
    {87u, {0x72, 7u}},        {88u, {0xfc, 8u}},
    {89u, {0x73, 7u}},        {90u, {0xfd, 8u}},
    {91u, {0x1ffb, 13u}},     {92u, {0x7fff0, 19u}},
    {93u, {0x1ffc, 13u}},     {94u, {0x3ffc, 14u}},
    {95u, {0x22, 6u}},        {96u, {0x7ffd, 15u}},
    {97u, {0x3, 5u}},         {98u, {0x23, 6u}},
    {99u, {0x4, 5u}},         {100u, {0x24, 6u}},
    {101u, {0x5, 5u}},        {102u, {0x25, 6u}},
    {103u, {0x26, 6u}},       {104u, {0x27, 6u}},
    {105u, {0x6, 5u}},        {106u, {0x74, 7u}},
    {107u, {0x75, 7u}},       {108u, {0x28, 6u}},
    {109u, {0x29, 6u}},       {110u, {0x2a, 6u}},
    {111u, {0x7, 5u}},        {112u, {0x2b, 6u}},
    {113u, {0x76, 7u}},       {114u, {0x2c, 6u}},
    {115u, {0x8, 5u}},        {116u, {0x9, 5u}},
    {117u, {0x2d, 6u}},       {118u, {0x77, 7u}},
    {119u, {0x78, 7u}},       {120u, {0x79, 7u}},
    {121u, {0x7a, 7u}},       {122u, {0x7b, 7u}},
    {123u, {0x7ffe, 15u}},    {124u, {0x7fc, 11u}},
    {125u, {0x3ffd, 14u}},    {126u, {0x1ffd, 13u}},
    {127u, {0xffffffc, 28u}}, {128u, {0xfffe6, 20u}},
    {129u, {0x3fffd2, 22u}},  {130u, {0xfffe7, 20u}},
    {131u, {0xfffe8, 20u}},   {132u, {0x3fffd3, 22u}},
    {133u, {0x3fffd4, 22u}},  {134u, {0x3fffd5, 22u}},
    {135u, {0x7fffd9, 23u}},  {136u, {0x3fffd6, 22u}},
    {137u, {0x7fffda, 23u}},  {138u, {0x7fffdb, 23u}},
    {139u, {0x7fffdc, 23u}},  {140u, {0x7fffdd, 23u}},
    {141u, {0x7fffde, 23u}},  {142u, {0xffffeb, 24u}},
    {143u, {0x7fffdf, 23u}},  {144u, {0xffffec, 24u}},
    {145u, {0xffffed, 24u}},  {146u, {0x3fffd7, 22u}},
    {147u, {0x7fffe0, 23u}},  {148u, {0xffffee, 24u}},
    {149u, {0x7fffe1, 23u}},  {150u, {0x7fffe2, 23u}},
    {151u, {0x7fffe3, 23u}},  {152u, {0x7fffe4, 23u}},
    {153u, {0x1fffdc, 21u}},  {154u, {0x3fffd8, 22u}},
    {155u, {0x7fffe5, 23u}},  {156u, {0x3fffd9, 22u}},
    {157u, {0x7fffe6, 23u}},  {158u, {0x7fffe7, 23u}},
    {159u, {0xffffef, 24u}},  {160u, {0x3fffda, 22u}},
    {161u, {0x1fffdd, 21u}},  {162u, {0xfffe9, 20u}},
    {163u, {0x3fffdb, 22u}},  {164u, {0x3fffdc, 22u}},
    {165u, {0x7fffe8, 23u}},  {166u, {0x7fffe9, 23u}},
    {167u, {0x1fffde, 21u}},  {168u, {0x7fffea, 23u}},
    {169u, {0x3fffdd, 22u}},  {170u, {0x3fffde, 22u}},
    {171u, {0xfffff0, 24u}},  {172u, {0x1fffdf, 21u}},
    {173u, {0x3fffdf, 22u}},  {174u, {0x7fffeb, 23u}},
    {175u, {0x7fffec, 23u}},  {176u, {0x1fffe0, 21u}},
    {177u, {0x1fffe1, 21u}},  {178u, {0x3fffe0, 22u}},
    {179u, {0x1fffe2, 21u}},  {180u, {0x7fffed, 23u}},
    {181u, {0x3fffe1, 22u}},  {182u, {0x7fffee, 23u}},
    {183u, {0x7fffef, 23u}},  {184u, {0xfffea, 20u}},
    {185u, {0x3fffe2, 22u}},  {186u, {0x3fffe3, 22u}},
    {187u, {0x3fffe4, 22u}},  {188u, {0x7ffff0, 23u}},
    {189u, {0x3fffe5, 22u}},  {190u, {0x3fffe6, 22u}},
    {191u, {0x7ffff1, 23u}},  {192u, {0x3ffffe0, 26u}},
    {193u, {0x3ffffe1, 26u}}, {194u, {0xfffeb, 20u}},
    {195u, {0x7fff1, 19u}},   {196u, {0x3fffe7, 22u}},
    {197u, {0x7ffff2, 23u}},  {198u, {0x3fffe8, 22u}},
    {199u, {0x1ffffec, 25u}}, {200u, {0x3ffffe2, 26u}},
    {201u, {0x3ffffe3, 26u}}, {202u, {0x3ffffe4, 26u}},
    {203u, {0x7ffffde, 27u}}, {204u, {0x7ffffdf, 27u}},
    {205u, {0x3ffffe5, 26u}}, {206u, {0xfffff1, 24u}},
    {207u, {0x1ffffed, 25u}}, {208u, {0x7fff2, 19u}},
    {209u, {0x1fffe3, 21u}},  {210u, {0x3ffffe6, 26u}},
    {211u, {0x7ffffe0, 27u}}, {212u, {0x7ffffe1, 27u}},
    {213u, {0x3ffffe7, 26u}}, {214u, {0x7ffffe2, 27u}},
    {215u, {0xfffff2, 24u}},  {216u, {0x1fffe4, 21u}},
    {217u, {0x1fffe5, 21u}},  {218u, {0x3ffffe8, 26u}},
    {219u, {0x3ffffe9, 26u}}, {220u, {0xffffffd, 28u}},
    {221u, {0x7ffffe3, 27u}}, {222u, {0x7ffffe4, 27u}},
    {223u, {0x7ffffe5, 27u}}, {224u, {0xfffec, 20u}},
    {225u, {0xfffff3, 24u}},  {226u, {0xfffed, 20u}},
    {227u, {0x1fffe6, 21u}},  {228u, {0x3fffe9, 22u}},
    {229u, {0x1fffe7, 21u}},  {230u, {0x1fffe8, 21u}},
    {231u, {0x7ffff3, 23u}},  {232u, {0x3fffea, 22u}},
    {233u, {0x3fffeb, 22u}},  {234u, {0x1ffffee, 25u}},
    {235u, {0x1ffffef, 25u}}, {236u, {0xfffff4, 24u}},
    {237u, {0xfffff5, 24u}},  {238u, {0x3ffffea, 26u}},
    {239u, {0x7ffff4, 23u}},  {240u, {0x3ffffeb, 26u}},
    {241u, {0x7ffffe6, 27u}}, {242u, {0x3ffffec, 26u}},
    {243u, {0x3ffffed, 26u}}, {244u, {0x7ffffe7, 27u}},
    {245u, {0x7ffffe8, 27u}}, {246u, {0x7ffffe9, 27u}},
    {247u, {0x7ffffea, 27u}}, {248u, {0x7ffffeb, 27u}},
    {249u, {0xffffffe, 28u}}, {250u, {0x7ffffec, 27u}},
    {251u, {0x7ffffed, 27u}}, {252u, {0x7ffffee, 27u}},
    {253u, {0x7ffffef, 27u}}, {254u, {0x7fffff0, 27u}},
    {255u, {0x3ffffee, 26u}}, {256u, {0x3fffffff, 30u}},
};

const decode_table_t decode_table{
    {5u,
     {{0x0, 48u},
      {0x1, 49u},
      {0x2, 50u},
      {0x3, 97u},
      {0x4, 99u},
      {0x5, 101u},
      {0x6, 105u},
      {0x7, 111u},
      {0x8, 115u},
      {0x9, 116u}}},
    {6u, {{0x14, 32u},  {0x15, 37u},  {0x16, 45u},  {0x17, 46u},  {0x18, 47u},
          {0x19, 51u},  {0x1a, 52u},  {0x1b, 53u},  {0x1c, 54u},  {0x1d, 55u},
          {0x1e, 56u},  {0x1f, 57u},  {0x20, 61u},  {0x21, 65u},  {0x22, 95u},
          {0x23, 98u},  {0x24, 100u}, {0x25, 102u}, {0x26, 103u}, {0x27, 104u},
          {0x28, 108u}, {0x29, 109u}, {0x2a, 110u}, {0x2b, 112u}, {0x2c, 114u},
          {0x2d, 117u}}},
    {7u, {{0x5c, 58u},  {0x5d, 66u},  {0x5e, 67u},  {0x5f, 68u},  {0x60, 69u},
          {0x61, 70u},  {0x62, 71u},  {0x63, 72u},  {0x64, 73u},  {0x65, 74u},
          {0x66, 75u},  {0x67, 76u},  {0x68, 77u},  {0x69, 78u},  {0x6a, 79u},
          {0x6b, 80u},  {0x6c, 81u},  {0x6d, 82u},  {0x6e, 83u},  {0x6f, 84u},
          {0x70, 85u},  {0x71, 86u},  {0x72, 87u},  {0x73, 89u},  {0x74, 106u},
          {0x75, 107u}, {0x76, 113u}, {0x77, 118u}, {0x78, 119u}, {0x79, 120u},
          {0x7a, 121u}, {0x7b, 122u}}},
    {8u,
     {{0xf8, 38u},
      {0xf9, 42u},
      {0xfa, 44u},
      {0xfb, 59u},
      {0xfc, 88u},
      {0xfd, 90u}}},
    {10u,
     {{0x3f8, 33u}, {0x3f9, 34u}, {0x3fa, 40u}, {0x3fb, 41u}, {0x3fc, 63u}}},
    {11u, {{0x7fa, 39u}, {0x7fb, 43u}, {0x7fc, 124u}}},
    {12u, {{0xffa, 35u}, {0xffb, 62u}}},
    {13u,
     {{0x1ff8, 0u},
      {0x1ff9, 36u},
      {0x1ffa, 64u},
      {0x1ffb, 91u},
      {0x1ffc, 93u},
      {0x1ffd, 126u}}},
    {14u, {{0x3ffc, 94u}, {0x3ffd, 125u}}},
    {15u, {{0x7ffc, 60u}, {0x7ffd, 96u}, {0x7ffe, 123u}}},
    {19u, {{0x7fff0, 92u}, {0x7fff1, 195u}, {0x7fff2, 208u}}},
    {20u,
     {{0xfffe6, 128u},
      {0xfffe7, 130u},
      {0xfffe8, 131u},
      {0xfffe9, 162u},
      {0xfffea, 184u},
      {0xfffeb, 194u},
      {0xfffec, 224u},
      {0xfffed, 226u}}},
    {21u,
     {{0x1fffdc, 153u},
      {0x1fffdd, 161u},
      {0x1fffde, 167u},
      {0x1fffdf, 172u},
      {0x1fffe0, 176u},
      {0x1fffe1, 177u},
      {0x1fffe2, 179u},
      {0x1fffe3, 209u},
      {0x1fffe4, 216u},
      {0x1fffe5, 217u},
      {0x1fffe6, 227u},
      {0x1fffe7, 229u},
      {0x1fffe8, 230u}}},
    {22u,
     {{0x3fffd2, 129u}, {0x3fffd3, 132u}, {0x3fffd4, 133u}, {0x3fffd5, 134u},
      {0x3fffd6, 136u}, {0x3fffd7, 146u}, {0x3fffd8, 154u}, {0x3fffd9, 156u},
      {0x3fffda, 160u}, {0x3fffdb, 163u}, {0x3fffdc, 164u}, {0x3fffdd, 169u},
      {0x3fffde, 170u}, {0x3fffdf, 173u}, {0x3fffe0, 178u}, {0x3fffe1, 181u},
      {0x3fffe2, 185u}, {0x3fffe3, 186u}, {0x3fffe4, 187u}, {0x3fffe5, 189u},
      {0x3fffe6, 190u}, {0x3fffe7, 196u}, {0x3fffe8, 198u}, {0x3fffe9, 228u},
      {0x3fffea, 232u}, {0x3fffeb, 233u}}},
    {23u,
     {{0x7fffd8, 1u},   {0x7fffd9, 135u}, {0x7fffda, 137u}, {0x7fffdb, 138u},
      {0x7fffdc, 139u}, {0x7fffdd, 140u}, {0x7fffde, 141u}, {0x7fffdf, 143u},
      {0x7fffe0, 147u}, {0x7fffe1, 149u}, {0x7fffe2, 150u}, {0x7fffe3, 151u},
      {0x7fffe4, 152u}, {0x7fffe5, 155u}, {0x7fffe6, 157u}, {0x7fffe7, 158u},
      {0x7fffe8, 165u}, {0x7fffe9, 166u}, {0x7fffea, 168u}, {0x7fffeb, 174u},
      {0x7fffec, 175u}, {0x7fffed, 180u}, {0x7fffee, 182u}, {0x7fffef, 183u},
      {0x7ffff0, 188u}, {0x7ffff1, 191u}, {0x7ffff2, 197u}, {0x7ffff3, 231u},
      {0x7ffff4, 239u}}},
    {24u,
     {{0xffffea, 9u},
      {0xffffeb, 142u},
      {0xffffec, 144u},
      {0xffffed, 145u},
      {0xffffee, 148u},
      {0xffffef, 159u},
      {0xfffff0, 171u},
      {0xfffff1, 206u},
      {0xfffff2, 215u},
      {0xfffff3, 225u},
      {0xfffff4, 236u},
      {0xfffff5, 237u}}},
    {25u,
     {{0x1ffffec, 199u},
      {0x1ffffed, 207u},
      {0x1ffffee, 234u},
      {0x1ffffef, 235u}}},
    {26u,
     {{0x3ffffe0, 192u},
      {0x3ffffe1, 193u},
      {0x3ffffe2, 200u},
      {0x3ffffe3, 201u},
      {0x3ffffe4, 202u},
      {0x3ffffe5, 205u},
      {0x3ffffe6, 210u},
      {0x3ffffe7, 213u},
      {0x3ffffe8, 218u},
      {0x3ffffe9, 219u},
      {0x3ffffea, 238u},
      {0x3ffffeb, 240u},
      {0x3ffffec, 242u},
      {0x3ffffed, 243u},
      {0x3ffffee, 255u}}},
    {27u,
     {{0x7ffffde, 203u},
      {0x7ffffdf, 204u},
      {0x7ffffe0, 211u},
      {0x7ffffe1, 212u},
      {0x7ffffe2, 214u},
      {0x7ffffe3, 221u},
      {0x7ffffe4, 222u},
      {0x7ffffe5, 223u},
      {0x7ffffe6, 241u},
      {0x7ffffe7, 244u},
      {0x7ffffe8, 245u},
      {0x7ffffe9, 246u},
      {0x7ffffea, 247u},
      {0x7ffffeb, 248u},
      {0x7ffffec, 250u},
      {0x7ffffed, 251u},
      {0x7ffffee, 252u},
      {0x7ffffef, 253u},
      {0x7fffff0, 254u}}},
    {28u,
     {{0xfffffe2, 2u},   {0xfffffe3, 3u},  {0xfffffe4, 4u},  {0xfffffe5, 5u},
      {0xfffffe6, 6u},   {0xfffffe7, 7u},  {0xfffffe8, 8u},  {0xfffffe9, 11u},
      {0xfffffea, 12u},  {0xfffffeb, 14u}, {0xfffffec, 15u}, {0xfffffed, 16u},
      {0xfffffee, 17u},  {0xfffffef, 18u}, {0xffffff0, 19u}, {0xffffff1, 20u},
      {0xffffff2, 21u},  {0xffffff3, 23u}, {0xffffff4, 24u}, {0xffffff5, 25u},
      {0xffffff6, 26u},  {0xffffff7, 27u}, {0xffffff8, 28u}, {0xffffff9, 29u},
      {0xffffffa, 30u},  {0xffffffb, 31u}, {0xffffffb, 31u}, {0xffffffc, 127u},
      {0xffffffd, 220u}, {0xffffffe, 249u}}},
    {30u,
     {{0x3ffffffc, 10u},
      {0x3ffffffd, 13u},
      {0x3ffffffe, 22u},
      {0x3fffffff, 256u}}},
};

}  // namespace huffman

}  // namespace mh2c
