// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _processmessageblock_HH_
#define _processmessageblock_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "processmessageblobkb.h"
#include "processmessageblocud.h"

namespace ap_rtl {

struct processmessageblock : public sc_module {
    // Port declarations 19
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<3> > intermediateHash_address0;
    sc_out< sc_logic > intermediateHash_ce0;
    sc_out< sc_logic > intermediateHash_we0;
    sc_out< sc_lv<32> > intermediateHash_d0;
    sc_in< sc_lv<32> > intermediateHash_q0;
    sc_out< sc_lv<3> > intermediateHash_address1;
    sc_out< sc_logic > intermediateHash_ce1;
    sc_out< sc_logic > intermediateHash_we1;
    sc_out< sc_lv<32> > intermediateHash_d1;
    sc_in< sc_lv<32> > intermediateHash_q1;
    sc_out< sc_lv<4> > messageBlock_address0;
    sc_out< sc_logic > messageBlock_ce0;
    sc_in< sc_lv<32> > messageBlock_q0;


    // Module declarations
    processmessageblock(sc_module_name name);
    SC_HAS_PROCESS(processmessageblock);

    ~processmessageblock();

    sc_trace_file* mVcdFile;

    processmessageblobkb* W_U;
    processmessageblocud* W_s_U;
    sc_signal< sc_lv<18> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<5> > i_fu_464_p2;
    sc_signal< sc_lv<5> > i_reg_1232;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<1> > icmp_ln121_fu_458_p2;
    sc_signal< sc_lv<4> > trunc_ln123_fu_475_p1;
    sc_signal< sc_lv<4> > trunc_ln123_reg_1242;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<1> > icmp_ln134_fu_489_p2;
    sc_signal< sc_lv<32> > W_q0;
    sc_signal< sc_lv<32> > W_load_reg_1255;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<32> > xor_ln136_1_fu_555_p2;
    sc_signal< sc_lv<32> > xor_ln136_1_reg_1270;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<7> > i_3_fu_674_p2;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<7> > i_4_fu_686_p2;
    sc_signal< sc_lv<7> > i_4_reg_1297;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<64> > zext_ln150_fu_692_p1;
    sc_signal< sc_lv<64> > zext_ln150_reg_1302;
    sc_signal< sc_lv<1> > icmp_ln148_fu_680_p2;
    sc_signal< sc_lv<3> > intermediateHash_add_1_reg_1317;
    sc_signal< sc_lv<32> > A_reg_1322;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<32> > B_reg_1328;
    sc_signal< sc_lv<3> > intermediateHash_add_2_reg_1334;
    sc_signal< sc_lv<3> > intermediateHash_add_3_reg_1339;
    sc_signal< sc_lv<32> > C_reg_1344;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<32> > D_reg_1350;
    sc_signal< sc_lv<3> > intermediateHash_add_4_reg_1356;
    sc_signal< sc_lv<3> > intermediateHash_add_5_reg_1361;
    sc_signal< sc_lv<32> > E_reg_1366;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<32> > F_reg_1372;
    sc_signal< sc_lv<3> > intermediateHash_add_6_reg_1378;
    sc_signal< sc_lv<3> > intermediateHash_add_7_reg_1383;
    sc_signal< sc_lv<32> > G_reg_1388;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<32> > H_reg_1394;
    sc_signal< sc_lv<7> > i_5_fu_721_p2;
    sc_signal< sc_lv<7> > i_5_reg_1403;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_lv<1> > icmp_ln28_fu_737_p2;
    sc_signal< sc_lv<1> > icmp_ln28_reg_1408;
    sc_signal< sc_lv<1> > icmp_ln167_fu_715_p2;
    sc_signal< sc_lv<32> > select_ln11_fu_883_p3;
    sc_signal< sc_lv<32> > select_ln11_reg_1413;
    sc_signal< sc_lv<32> > select_ln28_3_fu_933_p3;
    sc_signal< sc_lv<32> > select_ln28_3_reg_1423;
    sc_signal< sc_lv<32> > G_1_fu_955_p3;
    sc_signal< sc_lv<32> > G_1_reg_1433;
    sc_signal< sc_lv<32> > xor_ln195_fu_975_p2;
    sc_signal< sc_lv<32> > xor_ln195_reg_1438;
    sc_signal< sc_lv<32> > xor_ln196_fu_980_p2;
    sc_signal< sc_lv<32> > xor_ln196_reg_1443;
    sc_signal< sc_lv<32> > TT1_fu_1101_p2;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<32> > C_1_fu_1138_p3;
    sc_signal< sc_lv<32> > E_1_fu_1196_p2;
    sc_signal< sc_lv<32> > xor_ln194_fu_1214_p2;
    sc_signal< sc_lv<32> > xor_ln194_reg_1463;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_lv<32> > xor_ln197_fu_1219_p2;
    sc_signal< sc_lv<32> > xor_ln197_reg_1468;
    sc_signal< sc_lv<7> > W_address0;
    sc_signal< sc_logic > W_ce0;
    sc_signal< sc_logic > W_we0;
    sc_signal< sc_lv<7> > W_address1;
    sc_signal< sc_logic > W_ce1;
    sc_signal< sc_logic > W_we1;
    sc_signal< sc_lv<32> > W_d1;
    sc_signal< sc_lv<32> > W_q1;
    sc_signal< sc_lv<6> > W_s_address0;
    sc_signal< sc_logic > W_s_ce0;
    sc_signal< sc_logic > W_s_we0;
    sc_signal< sc_lv<32> > W_s_d0;
    sc_signal< sc_lv<32> > W_s_q0;
    sc_signal< sc_lv<5> > i_0_reg_330;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<7> > i_1_reg_341;
    sc_signal< sc_lv<7> > i_2_reg_353;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<32> > Y_assign_2_reg_364;
    sc_signal< sc_lv<32> > F_1_reg_373;
    sc_signal< sc_lv<32> > D_0_reg_384;
    sc_signal< sc_lv<32> > D_1_reg_394;
    sc_signal< sc_lv<32> > Y_assign_reg_405;
    sc_signal< sc_lv<32> > B_1_reg_415;
    sc_signal< sc_lv<7> > i_assign_reg_426;
    sc_signal< sc_lv<32> > H_1_reg_437;
    sc_signal< sc_lv<32> > H_0_reg_447;
    sc_signal< sc_lv<64> > zext_ln123_fu_470_p1;
    sc_signal< sc_lv<64> > zext_ln123_1_fu_484_p1;
    sc_signal< sc_lv<64> > zext_ln136_fu_501_p1;
    sc_signal< sc_lv<64> > zext_ln136_1_fu_512_p1;
    sc_signal< sc_lv<64> > zext_ln136_2_fu_523_p1;
    sc_signal< sc_lv<64> > zext_ln137_1_fu_567_p1;
    sc_signal< sc_lv<64> > zext_ln137_2_fu_578_p1;
    sc_signal< sc_lv<64> > zext_ln137_fu_669_p1;
    sc_signal< sc_lv<64> > zext_ln150_1_fu_703_p1;
    sc_signal< sc_lv<64> > zext_ln174_fu_891_p1;
    sc_signal< sc_lv<32> > xor_ln190_fu_963_p2;
    sc_signal< sc_lv<32> > xor_ln191_fu_969_p2;
    sc_signal< sc_lv<32> > xor_ln192_fu_1202_p2;
    sc_signal< sc_lv<32> > xor_ln193_fu_1208_p2;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_logic > ap_CS_fsm_state18;
    sc_signal< sc_lv<4> > xor_ln123_fu_479_p2;
    sc_signal< sc_lv<7> > add_ln136_fu_495_p2;
    sc_signal< sc_lv<7> > add_ln136_1_fu_506_p2;
    sc_signal< sc_lv<7> > add_ln136_2_fu_517_p2;
    sc_signal< sc_lv<17> > trunc_ln12_fu_528_p1;
    sc_signal< sc_lv<15> > lshr_ln12_4_fu_532_p4;
    sc_signal< sc_lv<32> > or_ln12_4_fu_542_p3;
    sc_signal< sc_lv<32> > xor_ln136_fu_550_p2;
    sc_signal< sc_lv<7> > add_ln137_fu_561_p2;
    sc_signal< sc_lv<7> > add_ln137_1_fu_572_p2;
    sc_signal< sc_lv<17> > trunc_ln12_1_fu_583_p1;
    sc_signal< sc_lv<15> > lshr_ln_fu_586_p4;
    sc_signal< sc_lv<9> > trunc_ln12_2_fu_603_p1;
    sc_signal< sc_lv<23> > lshr_ln12_1_fu_606_p4;
    sc_signal< sc_lv<25> > trunc_ln12_3_fu_623_p1;
    sc_signal< sc_lv<7> > lshr_ln12_5_fu_627_p4;
    sc_signal< sc_lv<32> > or_ln_fu_595_p3;
    sc_signal< sc_lv<32> > or_ln12_1_fu_615_p3;
    sc_signal< sc_lv<32> > or_ln12_5_fu_637_p3;
    sc_signal< sc_lv<32> > xor_ln137_2_fu_651_p2;
    sc_signal< sc_lv<32> > xor_ln137_3_fu_657_p2;
    sc_signal< sc_lv<32> > xor_ln137_fu_645_p2;
    sc_signal< sc_lv<7> > add_ln150_fu_697_p2;
    sc_signal< sc_lv<3> > tmp_fu_727_p4;
    sc_signal< sc_lv<6> > trunc_ln172_fu_759_p1;
    sc_signal< sc_lv<32> > select_ln28_1_fu_751_p3;
    sc_signal< sc_lv<32> > zext_ln12_fu_769_p1;
    sc_signal< sc_lv<7> > zext_ln12_1_fu_773_p1;
    sc_signal< sc_lv<7> > sub_ln12_fu_783_p2;
    sc_signal< sc_lv<31> > select_ln28_fu_743_p3;
    sc_signal< sc_lv<31> > sext_ln12_fu_789_p1;
    sc_signal< sc_lv<32> > shl_ln12_fu_777_p2;
    sc_signal< sc_lv<31> > trunc_ln12_5_fu_799_p1;
    sc_signal< sc_lv<31> > lshr_ln12_fu_793_p2;
    sc_signal< sc_lv<1> > tmp_1_fu_809_p3;
    sc_signal< sc_lv<31> > or_ln12_fu_803_p2;
    sc_signal< sc_lv<6> > xor_ln14_fu_825_p2;
    sc_signal< sc_lv<32> > sext_ln14_fu_831_p1;
    sc_signal< sc_lv<7> > sub_ln14_fu_841_p2;
    sc_signal< sc_lv<31> > zext_ln14_fu_847_p1;
    sc_signal< sc_lv<32> > shl_ln14_fu_835_p2;
    sc_signal< sc_lv<31> > trunc_ln14_fu_857_p1;
    sc_signal< sc_lv<31> > lshr_ln14_fu_851_p2;
    sc_signal< sc_lv<1> > tmp_2_fu_867_p3;
    sc_signal< sc_lv<31> > or_ln14_fu_861_p2;
    sc_signal< sc_lv<1> > icmp_ln11_fu_763_p2;
    sc_signal< sc_lv<32> > or_ln12_i_fu_817_p3;
    sc_signal< sc_lv<32> > or_ln14_i_fu_875_p3;
    sc_signal< sc_lv<32> > xor_ln61_fu_897_p2;
    sc_signal< sc_lv<32> > xor_ln63_fu_915_p2;
    sc_signal< sc_lv<32> > and_ln63_1_fu_921_p2;
    sc_signal< sc_lv<32> > and_ln63_fu_909_p2;
    sc_signal< sc_lv<32> > xor_ln61_1_fu_903_p2;
    sc_signal< sc_lv<32> > or_ln63_fu_927_p2;
    sc_signal< sc_lv<13> > trunc_ln12_8_fu_941_p1;
    sc_signal< sc_lv<19> > lshr_ln12_s_fu_945_p4;
    sc_signal< sc_lv<20> > trunc_ln12_4_fu_985_p1;
    sc_signal< sc_lv<12> > lshr_ln12_6_fu_989_p4;
    sc_signal< sc_lv<32> > or_ln12_6_fu_999_p3;
    sc_signal< sc_lv<32> > add_ln172_fu_1007_p2;
    sc_signal< sc_lv<32> > add_ln172_1_fu_1012_p2;
    sc_signal< sc_lv<25> > trunc_ln12_6_fu_1018_p1;
    sc_signal< sc_lv<7> > lshr_ln12_8_fu_1022_p4;
    sc_signal< sc_lv<32> > SS1_fu_1032_p3;
    sc_signal< sc_lv<32> > xor_ln45_fu_1046_p2;
    sc_signal< sc_lv<32> > or_ln47_fu_1058_p2;
    sc_signal< sc_lv<32> > and_ln47_fu_1064_p2;
    sc_signal< sc_lv<32> > and_ln47_1_fu_1070_p2;
    sc_signal< sc_lv<32> > xor_ln45_1_fu_1052_p2;
    sc_signal< sc_lv<32> > or_ln47_1_fu_1076_p2;
    sc_signal< sc_lv<32> > select_ln28_2_fu_1082_p3;
    sc_signal< sc_lv<32> > SS2_fu_1040_p2;
    sc_signal< sc_lv<32> > add_ln174_fu_1089_p2;
    sc_signal< sc_lv<32> > add_ln174_1_fu_1095_p2;
    sc_signal< sc_lv<32> > add_ln175_fu_1107_p2;
    sc_signal< sc_lv<32> > add_ln175_1_fu_1113_p2;
    sc_signal< sc_lv<23> > trunc_ln12_7_fu_1124_p1;
    sc_signal< sc_lv<9> > lshr_ln12_9_fu_1128_p4;
    sc_signal< sc_lv<32> > TT2_fu_1118_p2;
    sc_signal< sc_lv<23> > trunc_ln12_9_fu_1146_p1;
    sc_signal< sc_lv<9> > lshr_ln12_2_fu_1150_p4;
    sc_signal< sc_lv<15> > trunc_ln12_10_fu_1168_p1;
    sc_signal< sc_lv<17> > lshr_ln12_3_fu_1172_p4;
    sc_signal< sc_lv<32> > or_ln12_3_fu_1182_p3;
    sc_signal< sc_lv<32> > xor_ln75_fu_1190_p2;
    sc_signal< sc_lv<32> > or_ln12_2_fu_1160_p3;
    sc_signal< sc_lv<18> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<18> ap_ST_fsm_state1;
    static const sc_lv<18> ap_ST_fsm_state2;
    static const sc_lv<18> ap_ST_fsm_state3;
    static const sc_lv<18> ap_ST_fsm_state4;
    static const sc_lv<18> ap_ST_fsm_state5;
    static const sc_lv<18> ap_ST_fsm_state6;
    static const sc_lv<18> ap_ST_fsm_state7;
    static const sc_lv<18> ap_ST_fsm_state8;
    static const sc_lv<18> ap_ST_fsm_state9;
    static const sc_lv<18> ap_ST_fsm_state10;
    static const sc_lv<18> ap_ST_fsm_state11;
    static const sc_lv<18> ap_ST_fsm_state12;
    static const sc_lv<18> ap_ST_fsm_state13;
    static const sc_lv<18> ap_ST_fsm_state14;
    static const sc_lv<18> ap_ST_fsm_state15;
    static const sc_lv<18> ap_ST_fsm_state16;
    static const sc_lv<18> ap_ST_fsm_state17;
    static const sc_lv<18> ap_ST_fsm_state18;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<7> ap_const_lv7_10;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<7> ap_const_lv7_0;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<64> ap_const_lv64_4;
    static const sc_lv<64> ap_const_lv64_5;
    static const sc_lv<64> ap_const_lv64_6;
    static const sc_lv<64> ap_const_lv64_7;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<5> ap_const_lv5_10;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<4> ap_const_lv4_F;
    static const sc_lv<7> ap_const_lv7_44;
    static const sc_lv<7> ap_const_lv7_70;
    static const sc_lv<7> ap_const_lv7_77;
    static const sc_lv<7> ap_const_lv7_7D;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<7> ap_const_lv7_73;
    static const sc_lv<7> ap_const_lv7_7A;
    static const sc_lv<32> ap_const_lv32_19;
    static const sc_lv<7> ap_const_lv7_1;
    static const sc_lv<7> ap_const_lv7_40;
    static const sc_lv<7> ap_const_lv7_4;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<31> ap_const_lv31_79CC4519;
    static const sc_lv<31> ap_const_lv31_7A879D8A;
    static const sc_lv<32> ap_const_lv32_79CC4519;
    static const sc_lv<32> ap_const_lv32_7A879D8A;
    static const sc_lv<6> ap_const_lv6_21;
    static const sc_lv<7> ap_const_lv7_20;
    static const sc_lv<6> ap_const_lv6_20;
    static const sc_lv<32> ap_const_lv32_FFFFFFFF;
    static const sc_lv<32> ap_const_lv32_14;
    static const sc_lv<32> ap_const_lv32_17;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_C_1_fu_1138_p3();
    void thread_E_1_fu_1196_p2();
    void thread_G_1_fu_955_p3();
    void thread_SS1_fu_1032_p3();
    void thread_SS2_fu_1040_p2();
    void thread_TT1_fu_1101_p2();
    void thread_TT2_fu_1118_p2();
    void thread_W_address0();
    void thread_W_address1();
    void thread_W_ce0();
    void thread_W_ce1();
    void thread_W_d1();
    void thread_W_s_address0();
    void thread_W_s_ce0();
    void thread_W_s_d0();
    void thread_W_s_we0();
    void thread_W_we0();
    void thread_W_we1();
    void thread_add_ln136_1_fu_506_p2();
    void thread_add_ln136_2_fu_517_p2();
    void thread_add_ln136_fu_495_p2();
    void thread_add_ln137_1_fu_572_p2();
    void thread_add_ln137_fu_561_p2();
    void thread_add_ln150_fu_697_p2();
    void thread_add_ln172_1_fu_1012_p2();
    void thread_add_ln172_fu_1007_p2();
    void thread_add_ln174_1_fu_1095_p2();
    void thread_add_ln174_fu_1089_p2();
    void thread_add_ln175_1_fu_1113_p2();
    void thread_add_ln175_fu_1107_p2();
    void thread_and_ln47_1_fu_1070_p2();
    void thread_and_ln47_fu_1064_p2();
    void thread_and_ln63_1_fu_921_p2();
    void thread_and_ln63_fu_909_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state14();
    void thread_ap_CS_fsm_state15();
    void thread_ap_CS_fsm_state16();
    void thread_ap_CS_fsm_state17();
    void thread_ap_CS_fsm_state18();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_i_3_fu_674_p2();
    void thread_i_4_fu_686_p2();
    void thread_i_5_fu_721_p2();
    void thread_i_fu_464_p2();
    void thread_icmp_ln11_fu_763_p2();
    void thread_icmp_ln121_fu_458_p2();
    void thread_icmp_ln134_fu_489_p2();
    void thread_icmp_ln148_fu_680_p2();
    void thread_icmp_ln167_fu_715_p2();
    void thread_icmp_ln28_fu_737_p2();
    void thread_intermediateHash_add_1_reg_1317();
    void thread_intermediateHash_add_2_reg_1334();
    void thread_intermediateHash_add_3_reg_1339();
    void thread_intermediateHash_add_4_reg_1356();
    void thread_intermediateHash_add_5_reg_1361();
    void thread_intermediateHash_add_6_reg_1378();
    void thread_intermediateHash_add_7_reg_1383();
    void thread_intermediateHash_address0();
    void thread_intermediateHash_address1();
    void thread_intermediateHash_ce0();
    void thread_intermediateHash_ce1();
    void thread_intermediateHash_d0();
    void thread_intermediateHash_d1();
    void thread_intermediateHash_we0();
    void thread_intermediateHash_we1();
    void thread_lshr_ln12_1_fu_606_p4();
    void thread_lshr_ln12_2_fu_1150_p4();
    void thread_lshr_ln12_3_fu_1172_p4();
    void thread_lshr_ln12_4_fu_532_p4();
    void thread_lshr_ln12_5_fu_627_p4();
    void thread_lshr_ln12_6_fu_989_p4();
    void thread_lshr_ln12_8_fu_1022_p4();
    void thread_lshr_ln12_9_fu_1128_p4();
    void thread_lshr_ln12_fu_793_p2();
    void thread_lshr_ln12_s_fu_945_p4();
    void thread_lshr_ln14_fu_851_p2();
    void thread_lshr_ln_fu_586_p4();
    void thread_messageBlock_address0();
    void thread_messageBlock_ce0();
    void thread_or_ln12_1_fu_615_p3();
    void thread_or_ln12_2_fu_1160_p3();
    void thread_or_ln12_3_fu_1182_p3();
    void thread_or_ln12_4_fu_542_p3();
    void thread_or_ln12_5_fu_637_p3();
    void thread_or_ln12_6_fu_999_p3();
    void thread_or_ln12_fu_803_p2();
    void thread_or_ln12_i_fu_817_p3();
    void thread_or_ln14_fu_861_p2();
    void thread_or_ln14_i_fu_875_p3();
    void thread_or_ln47_1_fu_1076_p2();
    void thread_or_ln47_fu_1058_p2();
    void thread_or_ln63_fu_927_p2();
    void thread_or_ln_fu_595_p3();
    void thread_select_ln11_fu_883_p3();
    void thread_select_ln28_1_fu_751_p3();
    void thread_select_ln28_2_fu_1082_p3();
    void thread_select_ln28_3_fu_933_p3();
    void thread_select_ln28_fu_743_p3();
    void thread_sext_ln12_fu_789_p1();
    void thread_sext_ln14_fu_831_p1();
    void thread_shl_ln12_fu_777_p2();
    void thread_shl_ln14_fu_835_p2();
    void thread_sub_ln12_fu_783_p2();
    void thread_sub_ln14_fu_841_p2();
    void thread_tmp_1_fu_809_p3();
    void thread_tmp_2_fu_867_p3();
    void thread_tmp_fu_727_p4();
    void thread_trunc_ln123_fu_475_p1();
    void thread_trunc_ln12_10_fu_1168_p1();
    void thread_trunc_ln12_1_fu_583_p1();
    void thread_trunc_ln12_2_fu_603_p1();
    void thread_trunc_ln12_3_fu_623_p1();
    void thread_trunc_ln12_4_fu_985_p1();
    void thread_trunc_ln12_5_fu_799_p1();
    void thread_trunc_ln12_6_fu_1018_p1();
    void thread_trunc_ln12_7_fu_1124_p1();
    void thread_trunc_ln12_8_fu_941_p1();
    void thread_trunc_ln12_9_fu_1146_p1();
    void thread_trunc_ln12_fu_528_p1();
    void thread_trunc_ln14_fu_857_p1();
    void thread_trunc_ln172_fu_759_p1();
    void thread_xor_ln123_fu_479_p2();
    void thread_xor_ln136_1_fu_555_p2();
    void thread_xor_ln136_fu_550_p2();
    void thread_xor_ln137_2_fu_651_p2();
    void thread_xor_ln137_3_fu_657_p2();
    void thread_xor_ln137_fu_645_p2();
    void thread_xor_ln14_fu_825_p2();
    void thread_xor_ln190_fu_963_p2();
    void thread_xor_ln191_fu_969_p2();
    void thread_xor_ln192_fu_1202_p2();
    void thread_xor_ln193_fu_1208_p2();
    void thread_xor_ln194_fu_1214_p2();
    void thread_xor_ln195_fu_975_p2();
    void thread_xor_ln196_fu_980_p2();
    void thread_xor_ln197_fu_1219_p2();
    void thread_xor_ln45_1_fu_1052_p2();
    void thread_xor_ln45_fu_1046_p2();
    void thread_xor_ln61_1_fu_903_p2();
    void thread_xor_ln61_fu_897_p2();
    void thread_xor_ln63_fu_915_p2();
    void thread_xor_ln75_fu_1190_p2();
    void thread_zext_ln123_1_fu_484_p1();
    void thread_zext_ln123_fu_470_p1();
    void thread_zext_ln12_1_fu_773_p1();
    void thread_zext_ln12_fu_769_p1();
    void thread_zext_ln136_1_fu_512_p1();
    void thread_zext_ln136_2_fu_523_p1();
    void thread_zext_ln136_fu_501_p1();
    void thread_zext_ln137_1_fu_567_p1();
    void thread_zext_ln137_2_fu_578_p1();
    void thread_zext_ln137_fu_669_p1();
    void thread_zext_ln14_fu_847_p1();
    void thread_zext_ln150_1_fu_703_p1();
    void thread_zext_ln150_fu_692_p1();
    void thread_zext_ln174_fu_891_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
