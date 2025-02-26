#pragma once

#include "../defaultCustomize.h"
#include "../param.h"
#include "../table.h"

const FixedRange pMeh0FR = {.start = 0, .end = 1};
// 0 eBAS Sub-Zero 0-1
const Param pMeh0 = {.name = "pMeh 0  eBAS Sub-Zero",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[0]),
                     .defaultValue = defaultCustTable.pMEH[0],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh0FR}}};
const FixedRange pMeh1FR = {.start = 0, .end = 4};
// 1 divMB Supressor 0-4
const Param pMeh1 = {.name = "pMeh 1  divMB Supressor",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[1]),
                     .defaultValue = defaultCustTable.pMEH[1],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh1FR}}};
const FixedRange pMeh2FR = {.start = 0, .end = 3};
// 2 1333>1065>800 0-3
const Param pMeh2 = {.name = "pMeh 2  1333>1065>800",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[2]),
                     .defaultValue = defaultCustTable.pMEH[2],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh2FR}}};
const FixedRange pMeh3FR = {.start = 0, .end = 4};
// 3 eBAW Shift 0-4
const Param pMeh3 = {.name = "pMeh 3  eBAW Shift",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[3]),
                     .defaultValue = defaultCustTable.pMEH[3],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh3FR}}};
const FixedRange pMeh4FR = {.start = 0, .end = 4};
// 4 eBAR Shift 0-4
const Param pMeh4 = {.name = "pMeh 4  eBAR Shift",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[4]),
                     .defaultValue = defaultCustTable.pMEH[4],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh4FR}}};
const FixedRange pMeh5FR = {.start = 0, .end = 4};
// 5 eBAW Crement 0-4
const Param pMeh5 = {.name = "pMeh 5  eBAW Crement",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[5]),
                     .defaultValue = defaultCustTable.pMEH[5],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh5FR}}};
const FixedRange pMeh6FR = {.start = 0, .end = 4};
// 6 eBAR Crement 0-4
const Param pMeh6 = {.name = "pMeh 6  eBAR Crement",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[6]),
                     .defaultValue = defaultCustTable.pMEH[6],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh6FR}}};
const FixedRange pMeh7FR = {.start = 0, .end = 4};
// 7 eBAS Crement 0-4
const Param pMeh7 = {.name = "pMeh 7  eBAS Crement",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[7]),
                     .defaultValue = defaultCustTable.pMEH[7],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh7FR}}};
const FixedRange pMeh8FR = {.start = 0, .end = 4};
// 8 RCD Decret 0-4
const Param pMeh8 = {.name = "pMeh 8  RCD Decret",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[8]),
                     .defaultValue = defaultCustTable.pMEH[8],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh8FR}}};
const FixedRange pMeh9FR = {.start = 0, .end = 4};
// 9 RP Decret 0-4
const Param pMeh9 = {.name = "pMeh 9  RP Decret",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.pMEH[9]),
                     .defaultValue = defaultCustTable.pMEH[9],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &pMeh9FR}}};
const FixedRange pMeh10FR = {.start = 0, .end = 8};
// 10 RAS Decret 0-8
const Param pMeh10 = {.name = "pMeh 10 RAS Decret",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[10]),
                      .defaultValue = defaultCustTable.pMEH[10],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh10FR}}};
const FixedRange pMeh11FR = {.start = 0, .end = 15};
// 11 SRPD 0-15
const Param pMeh11 = {.name = "pMeh 11 SRPD",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[11]),
                      .defaultValue = defaultCustTable.pMEH[11],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh11FR}}};
const FixedRange pMeh12FR = {.start = 0, .end = 1};
// 12 E-Enhance P 0-1
const Param pMeh12 = {.name = "pMeh 12 E-Enhance P",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[12]),
                      .defaultValue = defaultCustTable.pMEH[12],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh12FR}}};
const FixedRange pMeh13FR = {.start = 0, .end = 8};
// 13 DR Debug 0-8
const Param pMeh13 = {.name = "pMeh 13 DR Debug",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[13]),
                      .defaultValue = defaultCustTable.pMEH[13],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh13FR}}};
const FixedRange pMeh14FR = {.start = 0, .end = 24};
// 14 GameChanger 0-24
const Param pMeh14 = {.name = "pMeh 14 GameChanger",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[14]),
                      .defaultValue = defaultCustTable.pMEH[14],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh14FR}}};
const FixedRange pMeh15FR = {.start = 0, .end = 1};
// 15 eFOS MK 0-1
const Param pMeh15 = {.name = "pMeh 15 eFOS MK",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[15]),
                      .defaultValue = defaultCustTable.pMEH[15],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh15FR}}};
const FixedRange pMeh16FR = {.start = 0, .end = 1};
// 16 lovec 0-1
const Param pMeh16 = {.name = "pMeh 16 lovec",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[16]),
                      .defaultValue = defaultCustTable.pMEH[16],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh16FR}}};
const FixedRange pMeh17FR = {.start = 0, .end = 3};
// 17 DBI 0-3
const Param pMeh17 = {.name = "pMeh 17 DBI",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[17]),
                      .defaultValue = defaultCustTable.pMEH[17],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh17FR}}};
const FixedRange pMeh18FR = {.start = 0, .end = 3};
// 18 eBAMATIC ST 0-3
const Param pMeh18 = {.name = "pMeh 18 eBAMATIC ST",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[18]),
                      .defaultValue = defaultCustTable.pMEH[18],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh18FR}}};
const FixedRange pMeh19FR = {.start = 0, .end = 9};
// 19 vMINetune 0-9
const Param pMeh19 = {.name = "pMeh 19 vMINetune",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[19]),
                      .defaultValue = defaultCustTable.pMEH[19],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh19FR}}};
const FixedRange pMeh20FR = {.start = 0, .end = 6};
// 20 rVDDick 0-6
const Param pMeh20 = {.name = "pMeh 20 rVDDick",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[20]),
                      .defaultValue = defaultCustTable.pMEH[20],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh20FR}}};
const FixedRange pMeh21FR = {.start = 0, .end = 9};
// 21 gVMINDick 0-9
const Param pMeh21 = {.name = "pMeh 21 gVMINDick",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.pMEH[21]),
                      .defaultValue = defaultCustTable.pMEH[21],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &pMeh21FR}}};

// DEF =  0  2  0  2  2  0  0  0  0  0  0  0  1  0  0  0  0  0  0  1  4  2  >> RESERVED >>
// NUM =  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
const Table pMehTable = {.name = "pMeh Table",
                         .description = NULL,
                         .baseOffset = getOffset(defaultCustTable.pMEH),
                         .paramsCount = 22,  // 22-23 RESERVED
                         .params = {&pMeh0,  &pMeh1,  &pMeh2,  &pMeh3,  &pMeh4,  &pMeh5,  &pMeh6,  &pMeh7,  &pMeh8,  &pMeh9,  &pMeh10,
                                    &pMeh11, &pMeh12, &pMeh13, &pMeh14, &pMeh15, &pMeh16, &pMeh17, &pMeh18, &pMeh19, &pMeh20, &pMeh21}};

const FixedRange sMeh0FR = {.start = 1, .end = 9};
// 0 ARB-Boost 1-9
const Param sMeh0 = {.name = "sMeh 0  ARB-Boost",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[0]),
                     .defaultValue = defaultCustTable.sMEH[0],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh0FR}}};
const FixedRange sMeh1FR = {.start = 0, .end = 4};
// 1 ARB-BCD 0-4
const Param sMeh1 = {.name = "sMeh 1  ARB-BCD",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[1]),
                     .defaultValue = defaultCustTable.sMEH[1],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh1FR}}};
const FixedRange sMeh2FR = {.start = 0, .end = 4};
// 2 ARB-BRP 0-4
const Param sMeh2 = {.name = "sMeh 2  ARB-BRP",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[2]),
                     .defaultValue = defaultCustTable.sMEH[2],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh2FR}}};
const FixedRange sMeh3FR = {.start = 0, .end = 4};
// 3 ARB-RTR 0-4
const Param sMeh3 = {.name = "sMeh 3  ARB-RTR",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[3]),
                     .defaultValue = defaultCustTable.sMEH[3],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh3FR}}};
const FixedRange sMeh4FR = {.start = 0, .end = 4};
// 4 ARB-RTW 0-4
const Param sMeh4 = {.name = "sMeh 4  ARB-RTW",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[4]),
                     .defaultValue = defaultCustTable.sMEH[4],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh4FR}}};
const FixedRange sMeh5FR = {.start = 0, .end = 4};
// 5 ARB-WTR 0-4
const Param sMeh5 = {.name = "sMeh 5  ARB-WTR",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[5]),
                     .defaultValue = defaultCustTable.sMEH[5],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh5FR}}};
const FixedRange sMeh6FR = {.start = 0, .end = 7};
// 6 eZQ Override 0-7
const Param sMeh6 = {.name = "sMeh 6  eZQ Override",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[6]),
                     .defaultValue = defaultCustTable.sMEH[6],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh6FR}}};
const FixedRange sMeh7FR = {.start = 0, .end = 1};
// 7 trDVFS 0-1
const Param sMeh7 = {.name = "sMeh 7  trDVFS",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[7]),
                     .defaultValue = defaultCustTable.sMEH[7],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh7FR}}};
const FixedRange sMeh8FR = {.start = 0, .end = 2};
// 8 E-Boost 0-2
const Param sMeh8 = {.name = "sMeh 8  E-Boost",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[8]),
                     .defaultValue = defaultCustTable.sMEH[8],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh8FR}}};
const FixedRange sMeh9FR = {.start = 0, .end = 1};
// 9 SSC Logic 0-1
const Param sMeh9 = {.name = "sMeh 9  SSC Logic",
                     .measure = NULL,
                     .description = NULL,
                     .offset = getOffset(defaultCustTable.sMEH[9]),
                     .defaultValue = defaultCustTable.sMEH[9],
                     .limitsCount = 1,
                     .limits = {{.type = EFixedRange, .values = &sMeh9FR}}};
const FixedRange sMeh10FR = {.start = 0, .end = 8};
// 10 Latent 0-8
const Param sMeh10 = {.name = "sMeh 10 Latent",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.sMEH[10]),
                      .defaultValue = defaultCustTable.sMEH[10],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &sMeh10FR}}};

const FixedRange sMeh11FR = {.start = 0, .end = 4};
// 11 REF-NEH 0-4
const Param sMeh11 = {.name = "sMeh 11 REF-NEH",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.sMEH[11]),
                      .defaultValue = defaultCustTable.sMEH[11],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &sMeh11FR}}};
const FixedRange sMeh12FR = {.start = 0, .end = 1};
// 12 Clatok 0-1
const Param sMeh12 = {.name = "sMeh 12 Clatok",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.sMEH[12]),
                      .defaultValue = defaultCustTable.sMEH[12],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &sMeh12FR}}};
const FixedRange sMeh13FR = {.start = 0, .end = 4};
// 13 CPriora 0-4
const Param sMeh13 = {.name = "sMeh 13 CPriora",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.sMEH[13]),
                      .defaultValue = defaultCustTable.sMEH[13],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &sMeh13FR}}};
const FixedRange sMeh14FR = {.start = 0, .end = 3};
// 14 GetLow 0-3
const Param sMeh14 = {.name = "sMeh 14 GetLow",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.sMEH[14]),
                      .defaultValue = defaultCustTable.sMEH[14],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &sMeh14FR}}};
const FixedRange sMeh15FR = {.start = 0, .end = 3};
// 15 GetHigh 0-3
const Param sMeh15 = {.name = "sMeh 15 GetHigh",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.sMEH[15]),
                      .defaultValue = defaultCustTable.sMEH[15],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &sMeh15FR}}};
const FixedRange sMeh16FR = {.start = 0, .end = 1};
// 16 SYK-LOH 0-1
const Param sMeh16 = {.name = "sMeh 16 SYK-LOH",
                      .measure = NULL,
                      .description = NULL,
                      .offset = getOffset(defaultCustTable.sMEH[16]),
                      .defaultValue = defaultCustTable.sMEH[16],
                      .limitsCount = 1,
                      .limits = {{.type = EFixedRange, .values = &sMeh16FR}}};

// SECONDARY MICRO-ENHANCE LOGIC (SAFE)
// DEF =  6  2  2  2  2  2  1  0  0  1  0  2  0  0  0  0  0 >> RESERVED >>
// NUM =  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
const Table sMehTable = {
    .name = "sMeh Table",
    .description = NULL,
    .baseOffset = getOffset(defaultCustTable.sMEH),
    .paramsCount = 17,
    .params = {&sMeh0, &sMeh1, &sMeh2, &sMeh3, &sMeh4, &sMeh5, &sMeh6, &sMeh7, &sMeh8, &sMeh9, &sMeh10, &sMeh11, &sMeh12, &sMeh13, &sMeh14, &sMeh15, &sMeh16}};

const Tables cMEHTables = {.count = 2, .tables = {&pMehTable, &sMehTable}};
