/* --- Generated the 9/4/2025 at 0:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. feb. 12 16:7:4 CET 2025) --- */
/* --- Command line: /home/jayesh/.opam/4.03.0/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__findpid_reset(Line_follower__findpid_mem* self) {
  self->v = true;
}

void Line_follower__findpid_step(int sen3, int sen1,
                                 Line_follower__findpid_out* _out,
                                 Line_follower__findpid_mem* self) {
  
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int z;
  int p;
  int d;
  int error;
  if (self->v) {
    v_1 = 0;
  } else {
    v_1 = self->error_1;
  };
  error = (sen3-sen1);
  d = (error-v_1);
  v_3 = (Line_follower__kd*d);
  p = error;
  v_2 = (Line_follower__kp*p);
  z = (v_2+v_3);
  v_4 = (z>0);
  if (v_4) {
    _out->pid = 15;
  } else {
    _out->pid = -15;
  };
  self->error_1 = error;
  self->v = false;;
}

void Line_follower__counter_reset(Line_follower__counter_mem* self) {
  self->flg_1 = false;
  self->bcount_1 = 0;
  self->c_1 = 0;
  self->pnr = false;
  self->ck = Line_follower__St_Initial;
}

void Line_follower__counter_step(int sen0, int sen1, int sen2, int sen3,
                                 int sen4, int beacon, int flag,
                                 Line_follower__counter_out* _out,
                                 Line_follower__counter_mem* self) {
  
  int v_5;
  int v;
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int r_St_WaitForNextIncrement;
  Line_follower__st s_St_WaitForNextIncrement;
  int r_St_CountIncrement;
  Line_follower__st s_St_CountIncrement;
  int r_St_Initial;
  Line_follower__st s_St_Initial;
  int nr_St_WaitForNextIncrement;
  Line_follower__st ns_St_WaitForNextIncrement;
  int bcount_St_WaitForNextIncrement;
  int c_St_WaitForNextIncrement;
  int nr_St_CountIncrement;
  Line_follower__st ns_St_CountIncrement;
  int bcount_St_CountIncrement;
  int c_St_CountIncrement;
  int nr_St_Initial;
  Line_follower__st ns_St_Initial;
  int bcount_St_Initial;
  int c_St_Initial;
  Line_follower__st ck_1;
  Line_follower__st s;
  Line_follower__st ns;
  int r;
  int nr;
  int c;
  int bcount;
  int flg;
  flg = flag;
  switch (self->ck) {
    case Line_follower__St_Initial:
      v_6 = (sen1+sen2);
      v_7 = (v_6+sen3);
      v_8 = (v_7<2250);
      v_9 = (flag&&v_8);
      if (v_9) {
        r_St_Initial = false;
        s_St_Initial = Line_follower__St_CountIncrement;
      } else {
        r_St_Initial = self->pnr;
        s_St_Initial = Line_follower__St_Initial;
      };
      s = s_St_Initial;
      r = r_St_Initial;
      break;
    case Line_follower__St_CountIncrement:
      r_St_CountIncrement = self->pnr;
      s_St_CountIncrement = Line_follower__St_CountIncrement;
      s = s_St_CountIncrement;
      r = r_St_CountIncrement;
      break;
    case Line_follower__St_WaitForNextIncrement:
      v = (self->bcount_1>1);
      v_5 = (flag&&v);
      if (v_5) {
        r_St_WaitForNextIncrement = false;
        s_St_WaitForNextIncrement = Line_follower__St_Initial;
      } else {
        r_St_WaitForNextIncrement = self->pnr;
        s_St_WaitForNextIncrement = Line_follower__St_WaitForNextIncrement;
      };
      s = s_St_WaitForNextIncrement;
      r = r_St_WaitForNextIncrement;
      break;
    default:
      break;
  };
  ck_1 = s;
  switch (ck_1) {
    case Line_follower__St_Initial:
      bcount_St_Initial = 0;
      c_St_Initial = self->c_1;
      nr_St_Initial = false;
      ns_St_Initial = Line_follower__St_Initial;
      c = c_St_Initial;
      bcount = bcount_St_Initial;
      ns = ns_St_Initial;
      nr = nr_St_Initial;
      break;
    case Line_follower__St_CountIncrement:
      bcount_St_CountIncrement = 0;
      c_St_CountIncrement = (self->c_1+1);
      if (true) {
        nr_St_CountIncrement = true;
      } else {
        nr_St_CountIncrement = false;
      };
      if (true) {
        ns_St_CountIncrement = Line_follower__St_WaitForNextIncrement;
      } else {
        ns_St_CountIncrement = Line_follower__St_CountIncrement;
      };
      c = c_St_CountIncrement;
      bcount = bcount_St_CountIncrement;
      ns = ns_St_CountIncrement;
      nr = nr_St_CountIncrement;
      break;
    case Line_follower__St_WaitForNextIncrement:
      c_St_WaitForNextIncrement = self->c_1;
      bcount_St_WaitForNextIncrement = (self->bcount_1+beacon);
      nr_St_WaitForNextIncrement = false;
      ns_St_WaitForNextIncrement = Line_follower__St_WaitForNextIncrement;
      c = c_St_WaitForNextIncrement;
      bcount = bcount_St_WaitForNextIncrement;
      ns = ns_St_WaitForNextIncrement;
      nr = nr_St_WaitForNextIncrement;
      break;
    default:
      break;
  };
  _out->finalcount = c;
  self->flg_1 = flg;
  self->bcount_1 = bcount;
  self->c_1 = c;
  self->pnr = nr;
  self->ck = ns;;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__findpid_reset(&self->findpid);
  Line_follower__counter_reset(&self->counter);
  self->rightflag3_1 = 0;
  self->leftflag3_1 = 0;
  self->rightflag2_1 = 0;
  self->leftflag2_1 = 0;
  self->rightflag1_1 = 0;
  self->leftflag1_1 = 0;
  self->pnr = false;
  self->ck = Line_follower__St_1_Forward;
}

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int ir_d_front,
                              int leftforwardDetection,
                              int leftbackwardDetection,
                              int rightforwardDetection,
                              int rightbackwardDetection, int beacon,
                              int second, Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__findpid_out Line_follower__findpid_out_st;
  Line_follower__counter_out Line_follower__counter_out_st;
  
  int v_35;
  int v_33;
  int v_38;
  int v_36;
  int v_41;
  int v_39;
  int v_44;
  int v_42;
  int v_47;
  int v_45;
  int v_76;
  int v_74;
  int v_73;
  int v_72;
  int v_71;
  int v_70;
  int v_69;
  int v_68;
  int v_67;
  int v_66;
  Line_follower__st_1 v_65;
  int v_64;
  Line_follower__st_1 v_63;
  int v_62;
  Line_follower__st_1 v_61;
  int v_60;
  Line_follower__st_1 v_59;
  int v_58;
  int v_57;
  int v_56;
  int v_55;
  int v_54;
  int v_53;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_48;
  int v_79;
  int v_77;
  int v_108;
  int v_106;
  int v_105;
  int v_104;
  int v_103;
  int v_102;
  int v_101;
  int v_100;
  int v_99;
  int v_98;
  Line_follower__st_1 v_97;
  int v_96;
  Line_follower__st_1 v_95;
  int v_94;
  Line_follower__st_1 v_93;
  int v_92;
  Line_follower__st_1 v_91;
  int v_90;
  int v_89;
  int v_88;
  int v_87;
  int v_86;
  int v_85;
  int v_84;
  int v_83;
  int v_82;
  int v_81;
  int v_80;
  int v_111;
  int v_109;
  int v_140;
  int v_138;
  int v_137;
  int v_136;
  int v_135;
  int v_134;
  int v_133;
  int v_132;
  int v_131;
  int v_130;
  Line_follower__st_1 v_129;
  int v_128;
  Line_follower__st_1 v_127;
  int v_126;
  Line_follower__st_1 v_125;
  int v_124;
  Line_follower__st_1 v_123;
  int v_122;
  int v_121;
  int v_120;
  int v_119;
  int v_118;
  int v_117;
  int v_116;
  int v_115;
  int v_114;
  int v_113;
  int v_112;
  int v_144;
  Line_follower__st_1 v_143;
  int v_142;
  Line_follower__st_1 v_141;
  int v_148;
  Line_follower__st_1 v_147;
  int v_146;
  Line_follower__st_1 v_145;
  int v_152;
  Line_follower__st_1 v_151;
  int v_150;
  Line_follower__st_1 v_149;
  int v_155;
  Line_follower__st_1 v_154;
  int v_153;
  int v_158;
  int v_156;
  int v_162;
  Line_follower__st_1 v_161;
  int v_160;
  Line_follower__st_1 v_159;
  int v_166;
  Line_follower__st_1 v_165;
  int v_164;
  Line_follower__st_1 v_163;
  int v_170;
  Line_follower__st_1 v_169;
  int v_168;
  Line_follower__st_1 v_167;
  int v_174;
  Line_follower__st_1 v_173;
  int v_172;
  Line_follower__st_1 v_171;
  int v_178;
  Line_follower__st_1 v_177;
  int v_176;
  Line_follower__st_1 v_175;
  int v_182;
  Line_follower__st_1 v_181;
  int v_180;
  Line_follower__st_1 v_179;
  int v_185;
  int v_183;
  int v_186;
  int v_189;
  int v_187;
  int v_190;
  int v_191;
  int v_194;
  int v_192;
  int v_199;
  int v_197;
  int v_196;
  int v_195;
  int v_200;
  int v_203;
  int v_201;
  int v_206;
  int v_204;
  int v_214;
  Line_follower__st_1 v_213;
  int v_212;
  Line_follower__st_1 v_211;
  int v_210;
  Line_follower__st_1 v_209;
  int v_208;
  Line_follower__st_1 v_207;
  int v_222;
  Line_follower__st_1 v_221;
  int v_220;
  Line_follower__st_1 v_219;
  int v_218;
  Line_follower__st_1 v_217;
  int v_216;
  Line_follower__st_1 v_215;
  int v_224;
  Line_follower__st_1 v_223;
  int v_226;
  Line_follower__st_1 v_225;
  int v_247;
  Line_follower__st_1 v_246;
  int v_245;
  Line_follower__st_1 v_244;
  int v_243;
  Line_follower__st_1 v_242;
  int v_241;
  Line_follower__st_1 v_240;
  int v_239;
  Line_follower__st_1 v_238;
  int v_237;
  Line_follower__st_1 v_236;
  int v_235;
  int v_234;
  int v_233;
  int v_232;
  int v_231;
  int v_230;
  int v_229;
  int v_228;
  int v_227;
  int v_259;
  Line_follower__st_1 v_258;
  int v_257;
  Line_follower__st_1 v_256;
  int v_255;
  Line_follower__st_1 v_254;
  int v_253;
  Line_follower__st_1 v_252;
  int v_251;
  Line_follower__st_1 v_250;
  int v_249;
  Line_follower__st_1 v_248;
  int v_271;
  Line_follower__st_1 v_270;
  int v_269;
  Line_follower__st_1 v_268;
  int v_267;
  Line_follower__st_1 v_266;
  int v_265;
  Line_follower__st_1 v_264;
  int v_263;
  Line_follower__st_1 v_262;
  int v_261;
  Line_follower__st_1 v_260;
  int v_283;
  Line_follower__st_1 v_282;
  int v_281;
  Line_follower__st_1 v_280;
  int v_279;
  Line_follower__st_1 v_278;
  int v_277;
  Line_follower__st_1 v_276;
  int v_275;
  Line_follower__st_1 v_274;
  int v_273;
  Line_follower__st_1 v_272;
  int v_293;
  Line_follower__st_1 v_292;
  int v_291;
  Line_follower__st_1 v_290;
  int v_289;
  Line_follower__st_1 v_288;
  int v_287;
  Line_follower__st_1 v_286;
  int v_285;
  Line_follower__st_1 v_284;
  int v_305;
  Line_follower__st_1 v_304;
  int v_303;
  Line_follower__st_1 v_302;
  int v_301;
  Line_follower__st_1 v_300;
  int v_299;
  Line_follower__st_1 v_298;
  int v_297;
  Line_follower__st_1 v_296;
  int v_295;
  int v_294;
  int v_313;
  Line_follower__st_1 v_312;
  int v_311;
  Line_follower__st_1 v_310;
  int v_309;
  Line_follower__st_1 v_308;
  int v_307;
  Line_follower__st_1 v_306;
  int nr_St_1_ExitState;
  Line_follower__st_1 ns_St_1_ExitState;
  int rightturn_count_St_1_ExitState;
  int timer1_St_1_ExitState;
  int timer_St_1_ExitState;
  int rightflag3_St_1_ExitState;
  int leftflag3_St_1_ExitState;
  int rightflag2_St_1_ExitState;
  int leftflag2_St_1_ExitState;
  int rightflag1_St_1_ExitState;
  int leftflag1_St_1_ExitState;
  int flag_St_1_ExitState;
  int dir_St_1_ExitState;
  int v_r_St_1_ExitState;
  int v_l_St_1_ExitState;
  int nr_St_1_Forward_1;
  Line_follower__st_1 ns_St_1_Forward_1;
  int rightturn_count_St_1_Forward_1;
  int timer1_St_1_Forward_1;
  int timer_St_1_Forward_1;
  int rightflag3_St_1_Forward_1;
  int leftflag3_St_1_Forward_1;
  int rightflag2_St_1_Forward_1;
  int leftflag2_St_1_Forward_1;
  int rightflag1_St_1_Forward_1;
  int leftflag1_St_1_Forward_1;
  int flag_St_1_Forward_1;
  int dir_St_1_Forward_1;
  int v_r_St_1_Forward_1;
  int v_l_St_1_Forward_1;
  int nr_St_1_LeftTurn_Park;
  Line_follower__st_1 ns_St_1_LeftTurn_Park;
  int rightturn_count_St_1_LeftTurn_Park;
  int timer1_St_1_LeftTurn_Park;
  int timer_St_1_LeftTurn_Park;
  int rightflag3_St_1_LeftTurn_Park;
  int leftflag3_St_1_LeftTurn_Park;
  int rightflag2_St_1_LeftTurn_Park;
  int leftflag2_St_1_LeftTurn_Park;
  int rightflag1_St_1_LeftTurn_Park;
  int leftflag1_St_1_LeftTurn_Park;
  int flag_St_1_LeftTurn_Park;
  int dir_St_1_LeftTurn_Park;
  int v_r_St_1_LeftTurn_Park;
  int v_l_St_1_LeftTurn_Park;
  int nr_St_1_RightTurn_Park;
  Line_follower__st_1 ns_St_1_RightTurn_Park;
  int rightturn_count_St_1_RightTurn_Park;
  int timer1_St_1_RightTurn_Park;
  int timer_St_1_RightTurn_Park;
  int rightflag3_St_1_RightTurn_Park;
  int leftflag3_St_1_RightTurn_Park;
  int rightflag2_St_1_RightTurn_Park;
  int leftflag2_St_1_RightTurn_Park;
  int rightflag1_St_1_RightTurn_Park;
  int leftflag1_St_1_RightTurn_Park;
  int flag_St_1_RightTurn_Park;
  int dir_St_1_RightTurn_Park;
  int v_r_St_1_RightTurn_Park;
  int v_l_St_1_RightTurn_Park;
  int nr_St_1_ParkrightBackward;
  Line_follower__st_1 ns_St_1_ParkrightBackward;
  int rightturn_count_St_1_ParkrightBackward;
  int timer1_St_1_ParkrightBackward;
  int timer_St_1_ParkrightBackward;
  int rightflag3_St_1_ParkrightBackward;
  int leftflag3_St_1_ParkrightBackward;
  int rightflag2_St_1_ParkrightBackward;
  int leftflag2_St_1_ParkrightBackward;
  int rightflag1_St_1_ParkrightBackward;
  int leftflag1_St_1_ParkrightBackward;
  int flag_St_1_ParkrightBackward;
  int dir_St_1_ParkrightBackward;
  int v_r_St_1_ParkrightBackward;
  int v_l_St_1_ParkrightBackward;
  int nr_St_1_ParkleftBackward;
  Line_follower__st_1 ns_St_1_ParkleftBackward;
  int rightturn_count_St_1_ParkleftBackward;
  int timer1_St_1_ParkleftBackward;
  int timer_St_1_ParkleftBackward;
  int rightflag3_St_1_ParkleftBackward;
  int leftflag3_St_1_ParkleftBackward;
  int rightflag2_St_1_ParkleftBackward;
  int leftflag2_St_1_ParkleftBackward;
  int rightflag1_St_1_ParkleftBackward;
  int leftflag1_St_1_ParkleftBackward;
  int flag_St_1_ParkleftBackward;
  int dir_St_1_ParkleftBackward;
  int v_r_St_1_ParkleftBackward;
  int v_l_St_1_ParkleftBackward;
  int nr_St_1_ParkingStartTS;
  Line_follower__st_1 ns_St_1_ParkingStartTS;
  int rightturn_count_St_1_ParkingStartTS;
  int timer1_St_1_ParkingStartTS;
  int timer_St_1_ParkingStartTS;
  int rightflag3_St_1_ParkingStartTS;
  int leftflag3_St_1_ParkingStartTS;
  int rightflag2_St_1_ParkingStartTS;
  int leftflag2_St_1_ParkingStartTS;
  int rightflag1_St_1_ParkingStartTS;
  int leftflag1_St_1_ParkingStartTS;
  int flag_St_1_ParkingStartTS;
  int dir_St_1_ParkingStartTS;
  int v_r_St_1_ParkingStartTS;
  int v_l_St_1_ParkingStartTS;
  int nr_St_1_DelayP2;
  Line_follower__st_1 ns_St_1_DelayP2;
  int rightturn_count_St_1_DelayP2;
  int timer1_St_1_DelayP2;
  int timer_St_1_DelayP2;
  int rightflag3_St_1_DelayP2;
  int leftflag3_St_1_DelayP2;
  int rightflag2_St_1_DelayP2;
  int leftflag2_St_1_DelayP2;
  int rightflag1_St_1_DelayP2;
  int leftflag1_St_1_DelayP2;
  int flag_St_1_DelayP2;
  int dir_St_1_DelayP2;
  int v_r_St_1_DelayP2;
  int v_l_St_1_DelayP2;
  int nr_St_1_ParkingStartSS;
  Line_follower__st_1 ns_St_1_ParkingStartSS;
  int rightturn_count_St_1_ParkingStartSS;
  int timer1_St_1_ParkingStartSS;
  int timer_St_1_ParkingStartSS;
  int rightflag3_St_1_ParkingStartSS;
  int leftflag3_St_1_ParkingStartSS;
  int rightflag2_St_1_ParkingStartSS;
  int leftflag2_St_1_ParkingStartSS;
  int rightflag1_St_1_ParkingStartSS;
  int leftflag1_St_1_ParkingStartSS;
  int flag_St_1_ParkingStartSS;
  int dir_St_1_ParkingStartSS;
  int v_r_St_1_ParkingStartSS;
  int v_l_St_1_ParkingStartSS;
  int nr_St_1_DelayP1;
  Line_follower__st_1 ns_St_1_DelayP1;
  int rightturn_count_St_1_DelayP1;
  int timer1_St_1_DelayP1;
  int timer_St_1_DelayP1;
  int rightflag3_St_1_DelayP1;
  int leftflag3_St_1_DelayP1;
  int rightflag2_St_1_DelayP1;
  int leftflag2_St_1_DelayP1;
  int rightflag1_St_1_DelayP1;
  int leftflag1_St_1_DelayP1;
  int flag_St_1_DelayP1;
  int dir_St_1_DelayP1;
  int v_r_St_1_DelayP1;
  int v_l_St_1_DelayP1;
  int nr_St_1_ParkingStartFS;
  Line_follower__st_1 ns_St_1_ParkingStartFS;
  int rightturn_count_St_1_ParkingStartFS;
  int timer1_St_1_ParkingStartFS;
  int timer_St_1_ParkingStartFS;
  int rightflag3_St_1_ParkingStartFS;
  int leftflag3_St_1_ParkingStartFS;
  int rightflag2_St_1_ParkingStartFS;
  int leftflag2_St_1_ParkingStartFS;
  int rightflag1_St_1_ParkingStartFS;
  int leftflag1_St_1_ParkingStartFS;
  int flag_St_1_ParkingStartFS;
  int dir_St_1_ParkingStartFS;
  int v_r_St_1_ParkingStartFS;
  int v_l_St_1_ParkingStartFS;
  int nr_St_1_PreParkingDriftRight;
  Line_follower__st_1 ns_St_1_PreParkingDriftRight;
  int rightturn_count_St_1_PreParkingDriftRight;
  int timer1_St_1_PreParkingDriftRight;
  int timer_St_1_PreParkingDriftRight;
  int rightflag3_St_1_PreParkingDriftRight;
  int leftflag3_St_1_PreParkingDriftRight;
  int rightflag2_St_1_PreParkingDriftRight;
  int leftflag2_St_1_PreParkingDriftRight;
  int rightflag1_St_1_PreParkingDriftRight;
  int leftflag1_St_1_PreParkingDriftRight;
  int flag_St_1_PreParkingDriftRight;
  int dir_St_1_PreParkingDriftRight;
  int v_r_St_1_PreParkingDriftRight;
  int v_l_St_1_PreParkingDriftRight;
  int nr_St_1_PreParkingDriftLeft;
  Line_follower__st_1 ns_St_1_PreParkingDriftLeft;
  int rightturn_count_St_1_PreParkingDriftLeft;
  int timer1_St_1_PreParkingDriftLeft;
  int timer_St_1_PreParkingDriftLeft;
  int rightflag3_St_1_PreParkingDriftLeft;
  int leftflag3_St_1_PreParkingDriftLeft;
  int rightflag2_St_1_PreParkingDriftLeft;
  int leftflag2_St_1_PreParkingDriftLeft;
  int rightflag1_St_1_PreParkingDriftLeft;
  int leftflag1_St_1_PreParkingDriftLeft;
  int flag_St_1_PreParkingDriftLeft;
  int dir_St_1_PreParkingDriftLeft;
  int v_r_St_1_PreParkingDriftLeft;
  int v_l_St_1_PreParkingDriftLeft;
  int nr_St_1_Forwardoneparking;
  Line_follower__st_1 ns_St_1_Forwardoneparking;
  int rightturn_count_St_1_Forwardoneparking;
  int timer1_St_1_Forwardoneparking;
  int timer_St_1_Forwardoneparking;
  int rightflag3_St_1_Forwardoneparking;
  int leftflag3_St_1_Forwardoneparking;
  int rightflag2_St_1_Forwardoneparking;
  int leftflag2_St_1_Forwardoneparking;
  int rightflag1_St_1_Forwardoneparking;
  int leftflag1_St_1_Forwardoneparking;
  int flag_St_1_Forwardoneparking;
  int dir_St_1_Forwardoneparking;
  int v_r_St_1_Forwardoneparking;
  int v_l_St_1_Forwardoneparking;
  int nr_St_1_FirstleftParking;
  Line_follower__st_1 ns_St_1_FirstleftParking;
  int rightturn_count_St_1_FirstleftParking;
  int timer1_St_1_FirstleftParking;
  int timer_St_1_FirstleftParking;
  int rightflag3_St_1_FirstleftParking;
  int leftflag3_St_1_FirstleftParking;
  int rightflag2_St_1_FirstleftParking;
  int leftflag2_St_1_FirstleftParking;
  int rightflag1_St_1_FirstleftParking;
  int leftflag1_St_1_FirstleftParking;
  int flag_St_1_FirstleftParking;
  int dir_St_1_FirstleftParking;
  int v_r_St_1_FirstleftParking;
  int v_l_St_1_FirstleftParking;
  int nr_St_1_Parking;
  Line_follower__st_1 ns_St_1_Parking;
  int rightturn_count_St_1_Parking;
  int timer1_St_1_Parking;
  int timer_St_1_Parking;
  int rightflag3_St_1_Parking;
  int leftflag3_St_1_Parking;
  int rightflag2_St_1_Parking;
  int leftflag2_St_1_Parking;
  int rightflag1_St_1_Parking;
  int leftflag1_St_1_Parking;
  int flag_St_1_Parking;
  int dir_St_1_Parking;
  int v_r_St_1_Parking;
  int v_l_St_1_Parking;
  int nr_St_1_ParkingDelay;
  Line_follower__st_1 ns_St_1_ParkingDelay;
  int rightturn_count_St_1_ParkingDelay;
  int timer1_St_1_ParkingDelay;
  int timer_St_1_ParkingDelay;
  int rightflag3_St_1_ParkingDelay;
  int leftflag3_St_1_ParkingDelay;
  int rightflag2_St_1_ParkingDelay;
  int leftflag2_St_1_ParkingDelay;
  int rightflag1_St_1_ParkingDelay;
  int leftflag1_St_1_ParkingDelay;
  int flag_St_1_ParkingDelay;
  int dir_St_1_ParkingDelay;
  int v_r_St_1_ParkingDelay;
  int v_l_St_1_ParkingDelay;
  int nr_St_1_ParkingDriftRightTS;
  Line_follower__st_1 ns_St_1_ParkingDriftRightTS;
  int rightturn_count_St_1_ParkingDriftRightTS;
  int timer1_St_1_ParkingDriftRightTS;
  int timer_St_1_ParkingDriftRightTS;
  int rightflag3_St_1_ParkingDriftRightTS;
  int leftflag3_St_1_ParkingDriftRightTS;
  int rightflag2_St_1_ParkingDriftRightTS;
  int leftflag2_St_1_ParkingDriftRightTS;
  int rightflag1_St_1_ParkingDriftRightTS;
  int leftflag1_St_1_ParkingDriftRightTS;
  int flag_St_1_ParkingDriftRightTS;
  int dir_St_1_ParkingDriftRightTS;
  int v_r_St_1_ParkingDriftRightTS;
  int v_l_St_1_ParkingDriftRightTS;
  int nr_St_1_ParkingDriftLeftTS;
  Line_follower__st_1 ns_St_1_ParkingDriftLeftTS;
  int rightturn_count_St_1_ParkingDriftLeftTS;
  int timer1_St_1_ParkingDriftLeftTS;
  int timer_St_1_ParkingDriftLeftTS;
  int rightflag3_St_1_ParkingDriftLeftTS;
  int leftflag3_St_1_ParkingDriftLeftTS;
  int rightflag2_St_1_ParkingDriftLeftTS;
  int leftflag2_St_1_ParkingDriftLeftTS;
  int rightflag1_St_1_ParkingDriftLeftTS;
  int leftflag1_St_1_ParkingDriftLeftTS;
  int flag_St_1_ParkingDriftLeftTS;
  int dir_St_1_ParkingDriftLeftTS;
  int v_r_St_1_ParkingDriftLeftTS;
  int v_l_St_1_ParkingDriftLeftTS;
  int nr_St_1_ParkingDriftRightSS;
  Line_follower__st_1 ns_St_1_ParkingDriftRightSS;
  int rightturn_count_St_1_ParkingDriftRightSS;
  int timer1_St_1_ParkingDriftRightSS;
  int timer_St_1_ParkingDriftRightSS;
  int rightflag3_St_1_ParkingDriftRightSS;
  int leftflag3_St_1_ParkingDriftRightSS;
  int rightflag2_St_1_ParkingDriftRightSS;
  int leftflag2_St_1_ParkingDriftRightSS;
  int rightflag1_St_1_ParkingDriftRightSS;
  int leftflag1_St_1_ParkingDriftRightSS;
  int flag_St_1_ParkingDriftRightSS;
  int dir_St_1_ParkingDriftRightSS;
  int v_r_St_1_ParkingDriftRightSS;
  int v_l_St_1_ParkingDriftRightSS;
  int nr_St_1_ParkingDriftLeftSS;
  Line_follower__st_1 ns_St_1_ParkingDriftLeftSS;
  int rightturn_count_St_1_ParkingDriftLeftSS;
  int timer1_St_1_ParkingDriftLeftSS;
  int timer_St_1_ParkingDriftLeftSS;
  int rightflag3_St_1_ParkingDriftLeftSS;
  int leftflag3_St_1_ParkingDriftLeftSS;
  int rightflag2_St_1_ParkingDriftLeftSS;
  int leftflag2_St_1_ParkingDriftLeftSS;
  int rightflag1_St_1_ParkingDriftLeftSS;
  int leftflag1_St_1_ParkingDriftLeftSS;
  int flag_St_1_ParkingDriftLeftSS;
  int dir_St_1_ParkingDriftLeftSS;
  int v_r_St_1_ParkingDriftLeftSS;
  int v_l_St_1_ParkingDriftLeftSS;
  int nr_St_1_ParkingDriftRight;
  Line_follower__st_1 ns_St_1_ParkingDriftRight;
  int rightturn_count_St_1_ParkingDriftRight;
  int timer1_St_1_ParkingDriftRight;
  int timer_St_1_ParkingDriftRight;
  int rightflag3_St_1_ParkingDriftRight;
  int leftflag3_St_1_ParkingDriftRight;
  int rightflag2_St_1_ParkingDriftRight;
  int leftflag2_St_1_ParkingDriftRight;
  int rightflag1_St_1_ParkingDriftRight;
  int leftflag1_St_1_ParkingDriftRight;
  int flag_St_1_ParkingDriftRight;
  int dir_St_1_ParkingDriftRight;
  int v_r_St_1_ParkingDriftRight;
  int v_l_St_1_ParkingDriftRight;
  int nr_St_1_ParkingDriftLeft;
  Line_follower__st_1 ns_St_1_ParkingDriftLeft;
  int rightturn_count_St_1_ParkingDriftLeft;
  int timer1_St_1_ParkingDriftLeft;
  int timer_St_1_ParkingDriftLeft;
  int rightflag3_St_1_ParkingDriftLeft;
  int leftflag3_St_1_ParkingDriftLeft;
  int rightflag2_St_1_ParkingDriftLeft;
  int leftflag2_St_1_ParkingDriftLeft;
  int rightflag1_St_1_ParkingDriftLeft;
  int leftflag1_St_1_ParkingDriftLeft;
  int flag_St_1_ParkingDriftLeft;
  int dir_St_1_ParkingDriftLeft;
  int v_r_St_1_ParkingDriftLeft;
  int v_l_St_1_ParkingDriftLeft;
  int nr_St_1_RightTurn3;
  Line_follower__st_1 ns_St_1_RightTurn3;
  int rightturn_count_St_1_RightTurn3;
  int timer1_St_1_RightTurn3;
  int timer_St_1_RightTurn3;
  int rightflag3_St_1_RightTurn3;
  int leftflag3_St_1_RightTurn3;
  int rightflag2_St_1_RightTurn3;
  int leftflag2_St_1_RightTurn3;
  int rightflag1_St_1_RightTurn3;
  int leftflag1_St_1_RightTurn3;
  int flag_St_1_RightTurn3;
  int dir_St_1_RightTurn3;
  int v_r_St_1_RightTurn3;
  int v_l_St_1_RightTurn3;
  int nr_St_1_Move5;
  Line_follower__st_1 ns_St_1_Move5;
  int rightturn_count_St_1_Move5;
  int timer1_St_1_Move5;
  int timer_St_1_Move5;
  int rightflag3_St_1_Move5;
  int leftflag3_St_1_Move5;
  int rightflag2_St_1_Move5;
  int leftflag2_St_1_Move5;
  int rightflag1_St_1_Move5;
  int leftflag1_St_1_Move5;
  int flag_St_1_Move5;
  int dir_St_1_Move5;
  int v_r_St_1_Move5;
  int v_l_St_1_Move5;
  int nr_St_1_LeftTurn2;
  Line_follower__st_1 ns_St_1_LeftTurn2;
  int rightturn_count_St_1_LeftTurn2;
  int timer1_St_1_LeftTurn2;
  int timer_St_1_LeftTurn2;
  int rightflag3_St_1_LeftTurn2;
  int leftflag3_St_1_LeftTurn2;
  int rightflag2_St_1_LeftTurn2;
  int leftflag2_St_1_LeftTurn2;
  int rightflag1_St_1_LeftTurn2;
  int leftflag1_St_1_LeftTurn2;
  int flag_St_1_LeftTurn2;
  int dir_St_1_LeftTurn2;
  int v_r_St_1_LeftTurn2;
  int v_l_St_1_LeftTurn2;
  int nr_St_1_Forward2;
  Line_follower__st_1 ns_St_1_Forward2;
  int rightturn_count_St_1_Forward2;
  int timer1_St_1_Forward2;
  int timer_St_1_Forward2;
  int rightflag3_St_1_Forward2;
  int leftflag3_St_1_Forward2;
  int rightflag2_St_1_Forward2;
  int leftflag2_St_1_Forward2;
  int rightflag1_St_1_Forward2;
  int leftflag1_St_1_Forward2;
  int flag_St_1_Forward2;
  int dir_St_1_Forward2;
  int v_r_St_1_Forward2;
  int v_l_St_1_Forward2;
  int nr_St_1_Move3;
  Line_follower__st_1 ns_St_1_Move3;
  int rightturn_count_St_1_Move3;
  int timer1_St_1_Move3;
  int timer_St_1_Move3;
  int rightflag3_St_1_Move3;
  int leftflag3_St_1_Move3;
  int rightflag2_St_1_Move3;
  int leftflag2_St_1_Move3;
  int rightflag1_St_1_Move3;
  int leftflag1_St_1_Move3;
  int flag_St_1_Move3;
  int dir_St_1_Move3;
  int v_r_St_1_Move3;
  int v_l_St_1_Move3;
  int nr_St_1_LeftTurn1;
  Line_follower__st_1 ns_St_1_LeftTurn1;
  int rightturn_count_St_1_LeftTurn1;
  int timer1_St_1_LeftTurn1;
  int timer_St_1_LeftTurn1;
  int rightflag3_St_1_LeftTurn1;
  int leftflag3_St_1_LeftTurn1;
  int rightflag2_St_1_LeftTurn1;
  int leftflag2_St_1_LeftTurn1;
  int rightflag1_St_1_LeftTurn1;
  int leftflag1_St_1_LeftTurn1;
  int flag_St_1_LeftTurn1;
  int dir_St_1_LeftTurn1;
  int v_r_St_1_LeftTurn1;
  int v_l_St_1_LeftTurn1;
  int nr_St_1_Forward1;
  Line_follower__st_1 ns_St_1_Forward1;
  int rightturn_count_St_1_Forward1;
  int timer1_St_1_Forward1;
  int timer_St_1_Forward1;
  int rightflag3_St_1_Forward1;
  int leftflag3_St_1_Forward1;
  int rightflag2_St_1_Forward1;
  int leftflag2_St_1_Forward1;
  int rightflag1_St_1_Forward1;
  int leftflag1_St_1_Forward1;
  int flag_St_1_Forward1;
  int dir_St_1_Forward1;
  int v_r_St_1_Forward1;
  int v_l_St_1_Forward1;
  int nr_St_1_Move1;
  Line_follower__st_1 ns_St_1_Move1;
  int rightturn_count_St_1_Move1;
  int timer1_St_1_Move1;
  int timer_St_1_Move1;
  int rightflag3_St_1_Move1;
  int leftflag3_St_1_Move1;
  int rightflag2_St_1_Move1;
  int leftflag2_St_1_Move1;
  int rightflag1_St_1_Move1;
  int leftflag1_St_1_Move1;
  int flag_St_1_Move1;
  int dir_St_1_Move1;
  int v_r_St_1_Move1;
  int v_l_St_1_Move1;
  int nr_St_1_RightTurn1;
  Line_follower__st_1 ns_St_1_RightTurn1;
  int rightturn_count_St_1_RightTurn1;
  int timer1_St_1_RightTurn1;
  int timer_St_1_RightTurn1;
  int rightflag3_St_1_RightTurn1;
  int leftflag3_St_1_RightTurn1;
  int rightflag2_St_1_RightTurn1;
  int leftflag2_St_1_RightTurn1;
  int rightflag1_St_1_RightTurn1;
  int leftflag1_St_1_RightTurn1;
  int flag_St_1_RightTurn1;
  int dir_St_1_RightTurn1;
  int v_r_St_1_RightTurn1;
  int v_l_St_1_RightTurn1;
  int nr_St_1_ObstacleAvoidance;
  Line_follower__st_1 ns_St_1_ObstacleAvoidance;
  int rightturn_count_St_1_ObstacleAvoidance;
  int timer1_St_1_ObstacleAvoidance;
  int timer_St_1_ObstacleAvoidance;
  int rightflag3_St_1_ObstacleAvoidance;
  int leftflag3_St_1_ObstacleAvoidance;
  int rightflag2_St_1_ObstacleAvoidance;
  int leftflag2_St_1_ObstacleAvoidance;
  int rightflag1_St_1_ObstacleAvoidance;
  int leftflag1_St_1_ObstacleAvoidance;
  int flag_St_1_ObstacleAvoidance;
  int dir_St_1_ObstacleAvoidance;
  int v_r_St_1_ObstacleAvoidance;
  int v_l_St_1_ObstacleAvoidance;
  int nr_St_1_BlackDriftRight;
  Line_follower__st_1 ns_St_1_BlackDriftRight;
  int rightturn_count_St_1_BlackDriftRight;
  int timer1_St_1_BlackDriftRight;
  int timer_St_1_BlackDriftRight;
  int rightflag3_St_1_BlackDriftRight;
  int leftflag3_St_1_BlackDriftRight;
  int rightflag2_St_1_BlackDriftRight;
  int leftflag2_St_1_BlackDriftRight;
  int rightflag1_St_1_BlackDriftRight;
  int leftflag1_St_1_BlackDriftRight;
  int flag_St_1_BlackDriftRight;
  int dir_St_1_BlackDriftRight;
  int v_r_St_1_BlackDriftRight;
  int v_l_St_1_BlackDriftRight;
  int nr_St_1_BlackDriftLeft;
  Line_follower__st_1 ns_St_1_BlackDriftLeft;
  int rightturn_count_St_1_BlackDriftLeft;
  int timer1_St_1_BlackDriftLeft;
  int timer_St_1_BlackDriftLeft;
  int rightflag3_St_1_BlackDriftLeft;
  int leftflag3_St_1_BlackDriftLeft;
  int rightflag2_St_1_BlackDriftLeft;
  int leftflag2_St_1_BlackDriftLeft;
  int rightflag1_St_1_BlackDriftLeft;
  int leftflag1_St_1_BlackDriftLeft;
  int flag_St_1_BlackDriftLeft;
  int dir_St_1_BlackDriftLeft;
  int v_r_St_1_BlackDriftLeft;
  int v_l_St_1_BlackDriftLeft;
  int nr_St_1_BlackRight;
  Line_follower__st_1 ns_St_1_BlackRight;
  int rightturn_count_St_1_BlackRight;
  int timer1_St_1_BlackRight;
  int timer_St_1_BlackRight;
  int rightflag3_St_1_BlackRight;
  int leftflag3_St_1_BlackRight;
  int rightflag2_St_1_BlackRight;
  int leftflag2_St_1_BlackRight;
  int rightflag1_St_1_BlackRight;
  int leftflag1_St_1_BlackRight;
  int flag_St_1_BlackRight;
  int dir_St_1_BlackRight;
  int v_r_St_1_BlackRight;
  int v_l_St_1_BlackRight;
  int nr_St_1_BlackLeft;
  Line_follower__st_1 ns_St_1_BlackLeft;
  int rightturn_count_St_1_BlackLeft;
  int timer1_St_1_BlackLeft;
  int timer_St_1_BlackLeft;
  int rightflag3_St_1_BlackLeft;
  int leftflag3_St_1_BlackLeft;
  int rightflag2_St_1_BlackLeft;
  int leftflag2_St_1_BlackLeft;
  int rightflag1_St_1_BlackLeft;
  int leftflag1_St_1_BlackLeft;
  int flag_St_1_BlackLeft;
  int dir_St_1_BlackLeft;
  int v_r_St_1_BlackLeft;
  int v_l_St_1_BlackLeft;
  int nr_St_1_BlackForward;
  Line_follower__st_1 ns_St_1_BlackForward;
  int rightturn_count_St_1_BlackForward;
  int timer1_St_1_BlackForward;
  int timer_St_1_BlackForward;
  int rightflag3_St_1_BlackForward;
  int leftflag3_St_1_BlackForward;
  int rightflag2_St_1_BlackForward;
  int leftflag2_St_1_BlackForward;
  int rightflag1_St_1_BlackForward;
  int leftflag1_St_1_BlackForward;
  int flag_St_1_BlackForward;
  int dir_St_1_BlackForward;
  int v_r_St_1_BlackForward;
  int v_l_St_1_BlackForward;
  int nr_St_1_DriftRight;
  Line_follower__st_1 ns_St_1_DriftRight;
  int rightturn_count_St_1_DriftRight;
  int timer1_St_1_DriftRight;
  int timer_St_1_DriftRight;
  int rightflag3_St_1_DriftRight;
  int leftflag3_St_1_DriftRight;
  int rightflag2_St_1_DriftRight;
  int leftflag2_St_1_DriftRight;
  int rightflag1_St_1_DriftRight;
  int leftflag1_St_1_DriftRight;
  int flag_St_1_DriftRight;
  int dir_St_1_DriftRight;
  int v_r_St_1_DriftRight;
  int v_l_St_1_DriftRight;
  int nr_St_1_DriftLeft;
  Line_follower__st_1 ns_St_1_DriftLeft;
  int rightturn_count_St_1_DriftLeft;
  int timer1_St_1_DriftLeft;
  int timer_St_1_DriftLeft;
  int rightflag3_St_1_DriftLeft;
  int leftflag3_St_1_DriftLeft;
  int rightflag2_St_1_DriftLeft;
  int leftflag2_St_1_DriftLeft;
  int rightflag1_St_1_DriftLeft;
  int leftflag1_St_1_DriftLeft;
  int flag_St_1_DriftLeft;
  int dir_St_1_DriftLeft;
  int v_r_St_1_DriftLeft;
  int v_l_St_1_DriftLeft;
  int nr_St_1_Right;
  Line_follower__st_1 ns_St_1_Right;
  int rightturn_count_St_1_Right;
  int timer1_St_1_Right;
  int timer_St_1_Right;
  int rightflag3_St_1_Right;
  int leftflag3_St_1_Right;
  int rightflag2_St_1_Right;
  int leftflag2_St_1_Right;
  int rightflag1_St_1_Right;
  int leftflag1_St_1_Right;
  int flag_St_1_Right;
  int dir_St_1_Right;
  int v_r_St_1_Right;
  int v_l_St_1_Right;
  int nr_St_1_Left;
  Line_follower__st_1 ns_St_1_Left;
  int rightturn_count_St_1_Left;
  int timer1_St_1_Left;
  int timer_St_1_Left;
  int rightflag3_St_1_Left;
  int leftflag3_St_1_Left;
  int rightflag2_St_1_Left;
  int leftflag2_St_1_Left;
  int rightflag1_St_1_Left;
  int leftflag1_St_1_Left;
  int flag_St_1_Left;
  int dir_St_1_Left;
  int v_r_St_1_Left;
  int v_l_St_1_Left;
  int nr_St_1_Stop;
  Line_follower__st_1 ns_St_1_Stop;
  int rightturn_count_St_1_Stop;
  int timer1_St_1_Stop;
  int timer_St_1_Stop;
  int rightflag3_St_1_Stop;
  int leftflag3_St_1_Stop;
  int rightflag2_St_1_Stop;
  int leftflag2_St_1_Stop;
  int rightflag1_St_1_Stop;
  int leftflag1_St_1_Stop;
  int flag_St_1_Stop;
  int dir_St_1_Stop;
  int v_r_St_1_Stop;
  int v_l_St_1_Stop;
  int nr_St_1_Forward;
  Line_follower__st_1 ns_St_1_Forward;
  int rightturn_count_St_1_Forward;
  int timer1_St_1_Forward;
  int timer_St_1_Forward;
  int rightflag3_St_1_Forward;
  int leftflag3_St_1_Forward;
  int rightflag2_St_1_Forward;
  int leftflag2_St_1_Forward;
  int rightflag1_St_1_Forward;
  int leftflag1_St_1_Forward;
  int flag_St_1_Forward;
  int dir_St_1_Forward;
  int v_r_St_1_Forward;
  int v_l_St_1_Forward;
  int v_32;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  int v_19;
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v;
  Line_follower__st_1 ns;
  int r;
  int nr;
  int pid;
  int wspeed;
  int bspeed;
  int pspeed;
  int oasspeed;
  int count;
  int flag;
  int leftflag1;
  int rightflag1;
  int leftflag2;
  int rightflag2;
  int leftflag3;
  int rightflag3;
  int c1;
  int c2;
  int c3;
  int c4;
  int c5;
  int blacknodedetected;
  int b3;
  int b4;
  int b5;
  int switch_condition;
  int timer;
  int timer1;
  int rightturn_count;
  r = self->pnr;
  v_31 = (sen2>700);
  v_30 = (sen3<700);
  b5 = (v_30&&v_31);
  v_29 = (sen2>700);
  v_28 = (sen1<700);
  b4 = (v_28&&v_29);
  b3 = (sen4<700);
  v_24 = (sen0+sen1);
  v_25 = (v_24+sen2);
  v_26 = (v_25+sen3);
  v_27 = (v_26+sen4);
  blacknodedetected = (v_27<3000);
  pspeed = 50;
  oasspeed = 40;
  wspeed = 50;
  v_22 = (sen0+sen1);
  v_23 = (v_22>1400);
  v_20 = (sen4>800);
  v_19 = (sen2<700);
  v_21 = (v_19&&v_20);
  switch_condition = (v_21&&v_23);
  v_18 = (sen2<800);
  v_17 = (sen3>900);
  c5 = (v_17&&v_18);
  v_16 = (sen2<800);
  v_15 = (sen1>900);
  c4 = (v_15&&v_16);
  c3 = (sen4>900);
  v_13 = (sen0*18);
  v_14 = (v_13/10);
  c2 = (v_14>900);
  v = (sen0+sen1);
  v_10 = (v+sen2);
  v_11 = (v_10+sen3);
  v_12 = (v_11+sen4);
  c1 = (v_12>4500);
  Line_follower__findpid_step(sen3, sen1, &Line_follower__findpid_out_st,
                              &self->findpid);
  pid = Line_follower__findpid_out_st.pid;
  switch (self->ck) {
    case Line_follower__St_1_Forward:
      rightturn_count_St_1_Forward = self->rightturn_count_1;
      timer1_St_1_Forward = self->timer1_1;
      timer_St_1_Forward = self->timer_1;
      rightflag3_St_1_Forward = self->rightflag3_1;
      leftflag3_St_1_Forward = self->leftflag3_1;
      rightflag2_St_1_Forward = self->rightflag2_1;
      leftflag2_St_1_Forward = self->leftflag2_1;
      rightflag1_St_1_Forward = self->rightflag1_1;
      leftflag1_St_1_Forward = self->leftflag1_1;
      dir_St_1_Forward = 1;
      flag_St_1_Forward = false;
      v_r_St_1_Forward = wspeed;
      v_l_St_1_Forward = wspeed;
      if (c5) {
        v_307 = true;
      } else {
        v_307 = false;
      };
      if (c4) {
        v_309 = true;
      } else {
        v_309 = v_307;
      };
      if (c3) {
        v_311 = true;
      } else {
        v_311 = v_309;
      };
      if (c2) {
        v_313 = true;
      } else {
        v_313 = v_311;
      };
      if (switch_condition) {
        nr_St_1_Forward = true;
      } else {
        nr_St_1_Forward = v_313;
      };
      if (c5) {
        v_306 = Line_follower__St_1_DriftLeft;
      } else {
        v_306 = Line_follower__St_1_Forward;
      };
      if (c4) {
        v_308 = Line_follower__St_1_DriftRight;
      } else {
        v_308 = v_306;
      };
      if (c3) {
        v_310 = Line_follower__St_1_Right;
      } else {
        v_310 = v_308;
      };
      if (c2) {
        v_312 = Line_follower__St_1_Left;
      } else {
        v_312 = v_310;
      };
      if (switch_condition) {
        ns_St_1_Forward = Line_follower__St_1_BlackForward;
      } else {
        ns_St_1_Forward = v_312;
      };
      _out->dir = dir_St_1_Forward;
      flag = flag_St_1_Forward;
      leftflag1 = leftflag1_St_1_Forward;
      rightflag1 = rightflag1_St_1_Forward;
      leftflag2 = leftflag2_St_1_Forward;
      rightflag2 = rightflag2_St_1_Forward;
      leftflag3 = leftflag3_St_1_Forward;
      rightflag3 = rightflag3_St_1_Forward;
      timer = timer_St_1_Forward;
      timer1 = timer1_St_1_Forward;
      rightturn_count = rightturn_count_St_1_Forward;
      break;
    case Line_follower__St_1_Stop:
      rightturn_count_St_1_Stop = self->rightturn_count_1;
      timer1_St_1_Stop = self->timer1_1;
      timer_St_1_Stop = self->timer_1;
      rightflag3_St_1_Stop = self->rightflag3_1;
      leftflag3_St_1_Stop = self->leftflag3_1;
      rightflag2_St_1_Stop = self->rightflag2_1;
      leftflag2_St_1_Stop = self->leftflag2_1;
      rightflag1_St_1_Stop = self->rightflag1_1;
      leftflag1_St_1_Stop = self->leftflag1_1;
      dir_St_1_Stop = 0;
      flag_St_1_Stop = false;
      v_r_St_1_Stop = 0;
      v_l_St_1_Stop = 0;
      if (true) {
        v_297 = true;
      } else {
        v_297 = false;
      };
      if (c5) {
        v_299 = true;
      } else {
        v_299 = v_297;
      };
      if (c4) {
        v_301 = true;
      } else {
        v_301 = v_299;
      };
      if (c3) {
        v_303 = true;
      } else {
        v_303 = v_301;
      };
      if (true) {
        v_296 = Line_follower__St_1_Forward;
      } else {
        v_296 = Line_follower__St_1_Stop;
      };
      if (c5) {
        v_298 = Line_follower__St_1_DriftLeft;
      } else {
        v_298 = v_296;
      };
      if (c4) {
        v_300 = Line_follower__St_1_DriftRight;
      } else {
        v_300 = v_298;
      };
      if (c3) {
        v_302 = Line_follower__St_1_Right;
      } else {
        v_302 = v_300;
      };
      v_294 = !(c1);
      v_295 = (v_294&&c2);
      if (v_295) {
        v_305 = true;
      } else {
        v_305 = v_303;
      };
      if (switch_condition) {
        nr_St_1_Stop = true;
      } else {
        nr_St_1_Stop = v_305;
      };
      if (v_295) {
        v_304 = Line_follower__St_1_Left;
      } else {
        v_304 = v_302;
      };
      if (switch_condition) {
        ns_St_1_Stop = Line_follower__St_1_BlackForward;
      } else {
        ns_St_1_Stop = v_304;
      };
      _out->dir = dir_St_1_Stop;
      flag = flag_St_1_Stop;
      leftflag1 = leftflag1_St_1_Stop;
      rightflag1 = rightflag1_St_1_Stop;
      leftflag2 = leftflag2_St_1_Stop;
      rightflag2 = rightflag2_St_1_Stop;
      leftflag3 = leftflag3_St_1_Stop;
      rightflag3 = rightflag3_St_1_Stop;
      timer = timer_St_1_Stop;
      timer1 = timer1_St_1_Stop;
      rightturn_count = rightturn_count_St_1_Stop;
      break;
    case Line_follower__St_1_Left:
      rightturn_count_St_1_Left = self->rightturn_count_1;
      timer1_St_1_Left = self->timer1_1;
      timer_St_1_Left = self->timer_1;
      rightflag3_St_1_Left = self->rightflag3_1;
      leftflag3_St_1_Left = self->leftflag3_1;
      rightflag2_St_1_Left = self->rightflag2_1;
      leftflag2_St_1_Left = self->leftflag2_1;
      rightflag1_St_1_Left = self->rightflag1_1;
      leftflag1_St_1_Left = self->leftflag1_1;
      dir_St_1_Left = 4;
      flag_St_1_Left = false;
      v_r_St_1_Left = wspeed;
      v_l_St_1_Left = wspeed;
      if (true) {
        v_285 = true;
      } else {
        v_285 = false;
      };
      if (c5) {
        v_287 = true;
      } else {
        v_287 = v_285;
      };
      if (c4) {
        v_289 = true;
      } else {
        v_289 = v_287;
      };
      if (c3) {
        v_291 = true;
      } else {
        v_291 = v_289;
      };
      if (switch_condition) {
        v_293 = true;
      } else {
        v_293 = v_291;
      };
      if (c1) {
        nr_St_1_Left = true;
      } else {
        nr_St_1_Left = v_293;
      };
      if (true) {
        v_284 = Line_follower__St_1_Forward;
      } else {
        v_284 = Line_follower__St_1_Left;
      };
      if (c5) {
        v_286 = Line_follower__St_1_DriftLeft;
      } else {
        v_286 = v_284;
      };
      if (c4) {
        v_288 = Line_follower__St_1_DriftRight;
      } else {
        v_288 = v_286;
      };
      if (c3) {
        v_290 = Line_follower__St_1_Right;
      } else {
        v_290 = v_288;
      };
      if (switch_condition) {
        v_292 = Line_follower__St_1_BlackForward;
      } else {
        v_292 = v_290;
      };
      if (c1) {
        ns_St_1_Left = Line_follower__St_1_Stop;
      } else {
        ns_St_1_Left = v_292;
      };
      _out->dir = dir_St_1_Left;
      flag = flag_St_1_Left;
      leftflag1 = leftflag1_St_1_Left;
      rightflag1 = rightflag1_St_1_Left;
      leftflag2 = leftflag2_St_1_Left;
      rightflag2 = rightflag2_St_1_Left;
      leftflag3 = leftflag3_St_1_Left;
      rightflag3 = rightflag3_St_1_Left;
      timer = timer_St_1_Left;
      timer1 = timer1_St_1_Left;
      rightturn_count = rightturn_count_St_1_Left;
      break;
    case Line_follower__St_1_Right:
      rightturn_count_St_1_Right = self->rightturn_count_1;
      timer1_St_1_Right = self->timer1_1;
      timer_St_1_Right = self->timer_1;
      rightflag3_St_1_Right = self->rightflag3_1;
      leftflag3_St_1_Right = self->leftflag3_1;
      rightflag2_St_1_Right = self->rightflag2_1;
      leftflag2_St_1_Right = self->leftflag2_1;
      rightflag1_St_1_Right = self->rightflag1_1;
      leftflag1_St_1_Right = self->leftflag1_1;
      dir_St_1_Right = 5;
      flag_St_1_Right = false;
      v_r_St_1_Right = wspeed;
      v_l_St_1_Right = wspeed;
      if (true) {
        v_273 = true;
      } else {
        v_273 = false;
      };
      if (c5) {
        v_275 = true;
      } else {
        v_275 = v_273;
      };
      if (c4) {
        v_277 = true;
      } else {
        v_277 = v_275;
      };
      if (c3) {
        v_279 = true;
      } else {
        v_279 = v_277;
      };
      if (c2) {
        v_281 = true;
      } else {
        v_281 = v_279;
      };
      if (switch_condition) {
        v_283 = true;
      } else {
        v_283 = v_281;
      };
      if (c1) {
        nr_St_1_Right = true;
      } else {
        nr_St_1_Right = v_283;
      };
      if (true) {
        v_272 = Line_follower__St_1_Forward;
      } else {
        v_272 = Line_follower__St_1_Right;
      };
      if (c5) {
        v_274 = Line_follower__St_1_DriftLeft;
      } else {
        v_274 = v_272;
      };
      if (c4) {
        v_276 = Line_follower__St_1_DriftRight;
      } else {
        v_276 = v_274;
      };
      if (c3) {
        v_278 = Line_follower__St_1_Right;
      } else {
        v_278 = v_276;
      };
      if (c2) {
        v_280 = Line_follower__St_1_Left;
      } else {
        v_280 = v_278;
      };
      if (switch_condition) {
        v_282 = Line_follower__St_1_BlackForward;
      } else {
        v_282 = v_280;
      };
      if (c1) {
        ns_St_1_Right = Line_follower__St_1_Stop;
      } else {
        ns_St_1_Right = v_282;
      };
      _out->dir = dir_St_1_Right;
      flag = flag_St_1_Right;
      leftflag1 = leftflag1_St_1_Right;
      rightflag1 = rightflag1_St_1_Right;
      leftflag2 = leftflag2_St_1_Right;
      rightflag2 = rightflag2_St_1_Right;
      leftflag3 = leftflag3_St_1_Right;
      rightflag3 = rightflag3_St_1_Right;
      timer = timer_St_1_Right;
      timer1 = timer1_St_1_Right;
      rightturn_count = rightturn_count_St_1_Right;
      break;
    case Line_follower__St_1_DriftLeft:
      rightturn_count_St_1_DriftLeft = self->rightturn_count_1;
      timer1_St_1_DriftLeft = self->timer1_1;
      timer_St_1_DriftLeft = self->timer_1;
      rightflag3_St_1_DriftLeft = self->rightflag3_1;
      leftflag3_St_1_DriftLeft = self->leftflag3_1;
      rightflag2_St_1_DriftLeft = self->rightflag2_1;
      leftflag2_St_1_DriftLeft = self->leftflag2_1;
      rightflag1_St_1_DriftLeft = self->rightflag1_1;
      leftflag1_St_1_DriftLeft = self->leftflag1_1;
      flag_St_1_DriftLeft = false;
      dir_St_1_DriftLeft = 3;
      v_r_St_1_DriftLeft = (wspeed+pid);
      v_l_St_1_DriftLeft = 0;
      if (true) {
        v_261 = true;
      } else {
        v_261 = false;
      };
      if (c5) {
        v_263 = true;
      } else {
        v_263 = v_261;
      };
      if (c4) {
        v_265 = true;
      } else {
        v_265 = v_263;
      };
      if (c3) {
        v_267 = true;
      } else {
        v_267 = v_265;
      };
      if (c2) {
        v_269 = true;
      } else {
        v_269 = v_267;
      };
      if (switch_condition) {
        v_271 = true;
      } else {
        v_271 = v_269;
      };
      if (c1) {
        nr_St_1_DriftLeft = true;
      } else {
        nr_St_1_DriftLeft = v_271;
      };
      if (true) {
        v_260 = Line_follower__St_1_Forward;
      } else {
        v_260 = Line_follower__St_1_DriftLeft;
      };
      if (c5) {
        v_262 = Line_follower__St_1_DriftLeft;
      } else {
        v_262 = v_260;
      };
      if (c4) {
        v_264 = Line_follower__St_1_DriftRight;
      } else {
        v_264 = v_262;
      };
      if (c3) {
        v_266 = Line_follower__St_1_Right;
      } else {
        v_266 = v_264;
      };
      if (c2) {
        v_268 = Line_follower__St_1_Left;
      } else {
        v_268 = v_266;
      };
      if (switch_condition) {
        v_270 = Line_follower__St_1_BlackForward;
      } else {
        v_270 = v_268;
      };
      if (c1) {
        ns_St_1_DriftLeft = Line_follower__St_1_Stop;
      } else {
        ns_St_1_DriftLeft = v_270;
      };
      _out->dir = dir_St_1_DriftLeft;
      flag = flag_St_1_DriftLeft;
      leftflag1 = leftflag1_St_1_DriftLeft;
      rightflag1 = rightflag1_St_1_DriftLeft;
      leftflag2 = leftflag2_St_1_DriftLeft;
      rightflag2 = rightflag2_St_1_DriftLeft;
      leftflag3 = leftflag3_St_1_DriftLeft;
      rightflag3 = rightflag3_St_1_DriftLeft;
      timer = timer_St_1_DriftLeft;
      timer1 = timer1_St_1_DriftLeft;
      rightturn_count = rightturn_count_St_1_DriftLeft;
      break;
    case Line_follower__St_1_DriftRight:
      rightturn_count_St_1_DriftRight = self->rightturn_count_1;
      timer1_St_1_DriftRight = self->timer1_1;
      timer_St_1_DriftRight = self->timer_1;
      rightflag3_St_1_DriftRight = self->rightflag3_1;
      leftflag3_St_1_DriftRight = self->leftflag3_1;
      rightflag2_St_1_DriftRight = self->rightflag2_1;
      leftflag2_St_1_DriftRight = self->leftflag2_1;
      rightflag1_St_1_DriftRight = self->rightflag1_1;
      leftflag1_St_1_DriftRight = self->leftflag1_1;
      flag_St_1_DriftRight = false;
      dir_St_1_DriftRight = 2;
      v_r_St_1_DriftRight = 0;
      v_l_St_1_DriftRight = (wspeed+pid);
      if (true) {
        v_249 = true;
      } else {
        v_249 = false;
      };
      if (c5) {
        v_251 = true;
      } else {
        v_251 = v_249;
      };
      if (c4) {
        v_253 = true;
      } else {
        v_253 = v_251;
      };
      if (c3) {
        v_255 = true;
      } else {
        v_255 = v_253;
      };
      if (c2) {
        v_257 = true;
      } else {
        v_257 = v_255;
      };
      if (switch_condition) {
        v_259 = true;
      } else {
        v_259 = v_257;
      };
      if (c1) {
        nr_St_1_DriftRight = true;
      } else {
        nr_St_1_DriftRight = v_259;
      };
      if (true) {
        v_248 = Line_follower__St_1_Forward;
      } else {
        v_248 = Line_follower__St_1_DriftRight;
      };
      if (c5) {
        v_250 = Line_follower__St_1_DriftLeft;
      } else {
        v_250 = v_248;
      };
      if (c4) {
        v_252 = Line_follower__St_1_DriftRight;
      } else {
        v_252 = v_250;
      };
      if (c3) {
        v_254 = Line_follower__St_1_Right;
      } else {
        v_254 = v_252;
      };
      if (c2) {
        v_256 = Line_follower__St_1_Left;
      } else {
        v_256 = v_254;
      };
      if (switch_condition) {
        v_258 = Line_follower__St_1_BlackForward;
      } else {
        v_258 = v_256;
      };
      if (c1) {
        ns_St_1_DriftRight = Line_follower__St_1_Stop;
      } else {
        ns_St_1_DriftRight = v_258;
      };
      _out->dir = dir_St_1_DriftRight;
      flag = flag_St_1_DriftRight;
      leftflag1 = leftflag1_St_1_DriftRight;
      rightflag1 = rightflag1_St_1_DriftRight;
      leftflag2 = leftflag2_St_1_DriftRight;
      rightflag2 = rightflag2_St_1_DriftRight;
      leftflag3 = leftflag3_St_1_DriftRight;
      rightflag3 = rightflag3_St_1_DriftRight;
      timer = timer_St_1_DriftRight;
      timer1 = timer1_St_1_DriftRight;
      rightturn_count = rightturn_count_St_1_DriftRight;
      break;
    case Line_follower__St_1_BlackForward:
      rightturn_count_St_1_BlackForward = self->rightturn_count_1;
      timer1_St_1_BlackForward = self->timer1_1;
      timer_St_1_BlackForward = self->timer_1;
      rightflag3_St_1_BlackForward = self->rightflag3_1;
      leftflag3_St_1_BlackForward = self->leftflag3_1;
      rightflag2_St_1_BlackForward = self->rightflag2_1;
      leftflag2_St_1_BlackForward = self->leftflag2_1;
      rightflag1_St_1_BlackForward = self->rightflag1_1;
      leftflag1_St_1_BlackForward = self->leftflag1_1;
      dir_St_1_BlackForward = 1;
      flag_St_1_BlackForward = true;
      if (true) {
        v_237 = true;
      } else {
        v_237 = false;
      };
      if (b4) {
        v_239 = true;
      } else {
        v_239 = v_237;
      };
      if (b5) {
        v_241 = true;
      } else {
        v_241 = v_239;
      };
      if (true) {
        v_236 = Line_follower__St_1_BlackForward;
      } else {
        v_236 = Line_follower__St_1_BlackForward;
      };
      if (b4) {
        v_238 = Line_follower__St_1_BlackDriftLeft;
      } else {
        v_238 = v_236;
      };
      if (b5) {
        v_240 = Line_follower__St_1_BlackDriftRight;
      } else {
        v_240 = v_238;
      };
      v_227 = (ir_d_front>-1);
      _out->dir = dir_St_1_BlackForward;
      flag = flag_St_1_BlackForward;
      leftflag1 = leftflag1_St_1_BlackForward;
      rightflag1 = rightflag1_St_1_BlackForward;
      leftflag2 = leftflag2_St_1_BlackForward;
      rightflag2 = rightflag2_St_1_BlackForward;
      leftflag3 = leftflag3_St_1_BlackForward;
      rightflag3 = rightflag3_St_1_BlackForward;
      timer = timer_St_1_BlackForward;
      timer1 = timer1_St_1_BlackForward;
      rightturn_count = rightturn_count_St_1_BlackForward;
      break;
    case Line_follower__St_1_BlackLeft:
      rightturn_count_St_1_BlackLeft = self->rightturn_count_1;
      timer1_St_1_BlackLeft = self->timer1_1;
      timer_St_1_BlackLeft = self->timer_1;
      rightflag3_St_1_BlackLeft = self->rightflag3_1;
      leftflag3_St_1_BlackLeft = self->leftflag3_1;
      rightflag2_St_1_BlackLeft = self->rightflag2_1;
      leftflag2_St_1_BlackLeft = self->leftflag2_1;
      rightflag1_St_1_BlackLeft = self->rightflag1_1;
      leftflag1_St_1_BlackLeft = self->leftflag1_1;
      dir_St_1_BlackLeft = 4;
      flag_St_1_BlackLeft = true;
      if (true) {
        v_226 = true;
      } else {
        v_226 = false;
      };
      if (blacknodedetected) {
        nr_St_1_BlackLeft = true;
      } else {
        nr_St_1_BlackLeft = v_226;
      };
      if (true) {
        v_225 = Line_follower__St_1_BlackForward;
      } else {
        v_225 = Line_follower__St_1_BlackLeft;
      };
      if (blacknodedetected) {
        ns_St_1_BlackLeft = Line_follower__St_1_BlackLeft;
      } else {
        ns_St_1_BlackLeft = v_225;
      };
      _out->dir = dir_St_1_BlackLeft;
      flag = flag_St_1_BlackLeft;
      leftflag1 = leftflag1_St_1_BlackLeft;
      rightflag1 = rightflag1_St_1_BlackLeft;
      leftflag2 = leftflag2_St_1_BlackLeft;
      rightflag2 = rightflag2_St_1_BlackLeft;
      leftflag3 = leftflag3_St_1_BlackLeft;
      rightflag3 = rightflag3_St_1_BlackLeft;
      timer = timer_St_1_BlackLeft;
      timer1 = timer1_St_1_BlackLeft;
      rightturn_count = rightturn_count_St_1_BlackLeft;
      break;
    case Line_follower__St_1_BlackRight:
      rightturn_count_St_1_BlackRight = self->rightturn_count_1;
      timer1_St_1_BlackRight = self->timer1_1;
      timer_St_1_BlackRight = self->timer_1;
      rightflag3_St_1_BlackRight = self->rightflag3_1;
      leftflag3_St_1_BlackRight = self->leftflag3_1;
      rightflag2_St_1_BlackRight = self->rightflag2_1;
      leftflag2_St_1_BlackRight = self->leftflag2_1;
      rightflag1_St_1_BlackRight = self->rightflag1_1;
      leftflag1_St_1_BlackRight = self->leftflag1_1;
      dir_St_1_BlackRight = 5;
      flag_St_1_BlackRight = true;
      if (true) {
        v_224 = true;
      } else {
        v_224 = false;
      };
      if (blacknodedetected) {
        nr_St_1_BlackRight = true;
      } else {
        nr_St_1_BlackRight = v_224;
      };
      if (true) {
        v_223 = Line_follower__St_1_BlackForward;
      } else {
        v_223 = Line_follower__St_1_BlackRight;
      };
      if (blacknodedetected) {
        ns_St_1_BlackRight = Line_follower__St_1_BlackRight;
      } else {
        ns_St_1_BlackRight = v_223;
      };
      _out->dir = dir_St_1_BlackRight;
      flag = flag_St_1_BlackRight;
      leftflag1 = leftflag1_St_1_BlackRight;
      rightflag1 = rightflag1_St_1_BlackRight;
      leftflag2 = leftflag2_St_1_BlackRight;
      rightflag2 = rightflag2_St_1_BlackRight;
      leftflag3 = leftflag3_St_1_BlackRight;
      rightflag3 = rightflag3_St_1_BlackRight;
      timer = timer_St_1_BlackRight;
      timer1 = timer1_St_1_BlackRight;
      rightturn_count = rightturn_count_St_1_BlackRight;
      break;
    case Line_follower__St_1_BlackDriftLeft:
      rightturn_count_St_1_BlackDriftLeft = self->rightturn_count_1;
      timer1_St_1_BlackDriftLeft = self->timer1_1;
      timer_St_1_BlackDriftLeft = self->timer_1;
      rightflag3_St_1_BlackDriftLeft = self->rightflag3_1;
      leftflag3_St_1_BlackDriftLeft = self->leftflag3_1;
      rightflag2_St_1_BlackDriftLeft = self->rightflag2_1;
      leftflag2_St_1_BlackDriftLeft = self->leftflag2_1;
      rightflag1_St_1_BlackDriftLeft = self->rightflag1_1;
      leftflag1_St_1_BlackDriftLeft = self->leftflag1_1;
      flag_St_1_BlackDriftLeft = true;
      dir_St_1_BlackDriftLeft = 3;
      v_l_St_1_BlackDriftLeft = 0;
      if (true) {
        v_216 = true;
      } else {
        v_216 = false;
      };
      if (b5) {
        v_218 = true;
      } else {
        v_218 = v_216;
      };
      if (b4) {
        v_220 = true;
      } else {
        v_220 = v_218;
      };
      if (switch_condition) {
        v_222 = true;
      } else {
        v_222 = v_220;
      };
      if (blacknodedetected) {
        nr_St_1_BlackDriftLeft = true;
      } else {
        nr_St_1_BlackDriftLeft = v_222;
      };
      if (true) {
        v_215 = Line_follower__St_1_BlackForward;
      } else {
        v_215 = Line_follower__St_1_BlackDriftLeft;
      };
      if (b5) {
        v_217 = Line_follower__St_1_BlackDriftLeft;
      } else {
        v_217 = v_215;
      };
      if (b4) {
        v_219 = Line_follower__St_1_BlackDriftRight;
      } else {
        v_219 = v_217;
      };
      if (switch_condition) {
        v_221 = Line_follower__St_1_BlackForward;
      } else {
        v_221 = v_219;
      };
      if (blacknodedetected) {
        ns_St_1_BlackDriftLeft = Line_follower__St_1_BlackRight;
      } else {
        ns_St_1_BlackDriftLeft = v_221;
      };
      _out->dir = dir_St_1_BlackDriftLeft;
      flag = flag_St_1_BlackDriftLeft;
      leftflag1 = leftflag1_St_1_BlackDriftLeft;
      rightflag1 = rightflag1_St_1_BlackDriftLeft;
      leftflag2 = leftflag2_St_1_BlackDriftLeft;
      rightflag2 = rightflag2_St_1_BlackDriftLeft;
      leftflag3 = leftflag3_St_1_BlackDriftLeft;
      rightflag3 = rightflag3_St_1_BlackDriftLeft;
      timer = timer_St_1_BlackDriftLeft;
      timer1 = timer1_St_1_BlackDriftLeft;
      rightturn_count = rightturn_count_St_1_BlackDriftLeft;
      break;
    case Line_follower__St_1_BlackDriftRight:
      rightturn_count_St_1_BlackDriftRight = self->rightturn_count_1;
      timer1_St_1_BlackDriftRight = self->timer1_1;
      timer_St_1_BlackDriftRight = self->timer_1;
      rightflag3_St_1_BlackDriftRight = self->rightflag3_1;
      leftflag3_St_1_BlackDriftRight = self->leftflag3_1;
      rightflag2_St_1_BlackDriftRight = self->rightflag2_1;
      leftflag2_St_1_BlackDriftRight = self->leftflag2_1;
      rightflag1_St_1_BlackDriftRight = self->rightflag1_1;
      leftflag1_St_1_BlackDriftRight = self->leftflag1_1;
      flag_St_1_BlackDriftRight = true;
      dir_St_1_BlackDriftRight = 2;
      v_r_St_1_BlackDriftRight = 0;
      if (true) {
        v_208 = true;
      } else {
        v_208 = false;
      };
      if (b5) {
        v_210 = true;
      } else {
        v_210 = v_208;
      };
      if (b4) {
        v_212 = true;
      } else {
        v_212 = v_210;
      };
      if (switch_condition) {
        v_214 = true;
      } else {
        v_214 = v_212;
      };
      if (blacknodedetected) {
        nr_St_1_BlackDriftRight = true;
      } else {
        nr_St_1_BlackDriftRight = v_214;
      };
      if (true) {
        v_207 = Line_follower__St_1_BlackForward;
      } else {
        v_207 = Line_follower__St_1_BlackDriftRight;
      };
      if (b5) {
        v_209 = Line_follower__St_1_BlackDriftLeft;
      } else {
        v_209 = v_207;
      };
      if (b4) {
        v_211 = Line_follower__St_1_BlackDriftRight;
      } else {
        v_211 = v_209;
      };
      if (switch_condition) {
        v_213 = Line_follower__St_1_BlackForward;
      } else {
        v_213 = v_211;
      };
      if (blacknodedetected) {
        ns_St_1_BlackDriftRight = Line_follower__St_1_BlackRight;
      } else {
        ns_St_1_BlackDriftRight = v_213;
      };
      _out->dir = dir_St_1_BlackDriftRight;
      flag = flag_St_1_BlackDriftRight;
      leftflag1 = leftflag1_St_1_BlackDriftRight;
      rightflag1 = rightflag1_St_1_BlackDriftRight;
      leftflag2 = leftflag2_St_1_BlackDriftRight;
      rightflag2 = rightflag2_St_1_BlackDriftRight;
      leftflag3 = leftflag3_St_1_BlackDriftRight;
      rightflag3 = rightflag3_St_1_BlackDriftRight;
      timer = timer_St_1_BlackDriftRight;
      timer1 = timer1_St_1_BlackDriftRight;
      rightturn_count = rightturn_count_St_1_BlackDriftRight;
      break;
    case Line_follower__St_1_ObstacleAvoidance:
      rightturn_count_St_1_ObstacleAvoidance = self->rightturn_count_1;
      timer1_St_1_ObstacleAvoidance = self->timer1_1;
      rightflag3_St_1_ObstacleAvoidance = self->rightflag3_1;
      leftflag3_St_1_ObstacleAvoidance = self->leftflag3_1;
      rightflag2_St_1_ObstacleAvoidance = self->rightflag2_1;
      leftflag2_St_1_ObstacleAvoidance = self->leftflag2_1;
      rightflag1_St_1_ObstacleAvoidance = self->rightflag1_1;
      leftflag1_St_1_ObstacleAvoidance = self->leftflag1_1;
      v_206 = (self->v_205-1);
      if (r) {
        timer_St_1_ObstacleAvoidance = 10;
      } else {
        timer_St_1_ObstacleAvoidance = v_206;
      };
      flag_St_1_ObstacleAvoidance = true;
      v_r_St_1_ObstacleAvoidance = 0;
      v_l_St_1_ObstacleAvoidance = 0;
      dir_St_1_ObstacleAvoidance = 0;
      _out->dir = dir_St_1_ObstacleAvoidance;
      flag = flag_St_1_ObstacleAvoidance;
      leftflag1 = leftflag1_St_1_ObstacleAvoidance;
      rightflag1 = rightflag1_St_1_ObstacleAvoidance;
      leftflag2 = leftflag2_St_1_ObstacleAvoidance;
      rightflag2 = rightflag2_St_1_ObstacleAvoidance;
      leftflag3 = leftflag3_St_1_ObstacleAvoidance;
      rightflag3 = rightflag3_St_1_ObstacleAvoidance;
      timer = timer_St_1_ObstacleAvoidance;
      v_204 = (timer<=0);
      if (v_204) {
        nr_St_1_ObstacleAvoidance = true;
        ns_St_1_ObstacleAvoidance = Line_follower__St_1_RightTurn1;
      } else {
        nr_St_1_ObstacleAvoidance = false;
        ns_St_1_ObstacleAvoidance = Line_follower__St_1_ObstacleAvoidance;
      };
      timer1 = timer1_St_1_ObstacleAvoidance;
      rightturn_count = rightturn_count_St_1_ObstacleAvoidance;
      break;
    case Line_follower__St_1_RightTurn1:
      rightturn_count_St_1_RightTurn1 = self->rightturn_count_1;
      timer1_St_1_RightTurn1 = self->timer1_1;
      rightflag3_St_1_RightTurn1 = self->rightflag3_1;
      leftflag3_St_1_RightTurn1 = self->leftflag3_1;
      rightflag2_St_1_RightTurn1 = self->rightflag2_1;
      leftflag2_St_1_RightTurn1 = self->leftflag2_1;
      rightflag1_St_1_RightTurn1 = self->rightflag1_1;
      leftflag1_St_1_RightTurn1 = self->leftflag1_1;
      v_203 = (self->v_202-1);
      if (r) {
        timer_St_1_RightTurn1 = 132;
      } else {
        timer_St_1_RightTurn1 = v_203;
      };
      flag_St_1_RightTurn1 = true;
      v_r_St_1_RightTurn1 = oasspeed;
      v_l_St_1_RightTurn1 = oasspeed;
      dir_St_1_RightTurn1 = 5;
      _out->dir = dir_St_1_RightTurn1;
      flag = flag_St_1_RightTurn1;
      leftflag1 = leftflag1_St_1_RightTurn1;
      rightflag1 = rightflag1_St_1_RightTurn1;
      leftflag2 = leftflag2_St_1_RightTurn1;
      rightflag2 = rightflag2_St_1_RightTurn1;
      leftflag3 = leftflag3_St_1_RightTurn1;
      rightflag3 = rightflag3_St_1_RightTurn1;
      timer = timer_St_1_RightTurn1;
      v_201 = (timer<=0);
      if (v_201) {
        nr_St_1_RightTurn1 = true;
        ns_St_1_RightTurn1 = Line_follower__St_1_Move1;
      } else {
        nr_St_1_RightTurn1 = false;
        ns_St_1_RightTurn1 = Line_follower__St_1_RightTurn1;
      };
      timer1 = timer1_St_1_RightTurn1;
      rightturn_count = rightturn_count_St_1_RightTurn1;
      break;
    case Line_follower__St_1_Move1:
      rightturn_count_St_1_Move1 = self->rightturn_count_1;
      timer1_St_1_Move1 = self->timer1_1;
      timer_St_1_Move1 = self->timer_1;
      rightflag3_St_1_Move1 = self->rightflag3_1;
      leftflag3_St_1_Move1 = self->leftflag3_1;
      rightflag2_St_1_Move1 = self->rightflag2_1;
      leftflag2_St_1_Move1 = self->leftflag2_1;
      rightflag1_St_1_Move1 = self->rightflag1_1;
      leftflag1_St_1_Move1 = self->leftflag1_1;
      flag_St_1_Move1 = true;
      v_r_St_1_Move1 = oasspeed;
      v_l_St_1_Move1 = oasspeed;
      dir_St_1_Move1 = 1;
      v_200 = (leftbackwardDetection==true);
      if (v_200) {
        nr_St_1_Move1 = true;
        ns_St_1_Move1 = Line_follower__St_1_Forward1;
      } else {
        nr_St_1_Move1 = false;
        ns_St_1_Move1 = Line_follower__St_1_Move1;
      };
      _out->dir = dir_St_1_Move1;
      flag = flag_St_1_Move1;
      leftflag1 = leftflag1_St_1_Move1;
      rightflag1 = rightflag1_St_1_Move1;
      leftflag2 = leftflag2_St_1_Move1;
      rightflag2 = rightflag2_St_1_Move1;
      leftflag3 = leftflag3_St_1_Move1;
      rightflag3 = rightflag3_St_1_Move1;
      timer = timer_St_1_Move1;
      timer1 = timer1_St_1_Move1;
      rightturn_count = rightturn_count_St_1_Move1;
      break;
    case Line_follower__St_1_Forward1:
      timer1_St_1_Forward1 = self->timer1_1;
      timer_St_1_Forward1 = self->timer_1;
      rightflag3_St_1_Forward1 = self->rightflag3_1;
      leftflag3_St_1_Forward1 = self->leftflag3_1;
      rightflag2_St_1_Forward1 = self->rightflag2_1;
      leftflag2_St_1_Forward1 = self->leftflag2_1;
      rightflag1_St_1_Forward1 = self->rightflag1_1;
      leftflag1_St_1_Forward1 = self->leftflag1_1;
      flag_St_1_Forward1 = true;
      v_r_St_1_Forward1 = oasspeed;
      v_l_St_1_Forward1 = oasspeed;
      dir_St_1_Forward1 = 1;
      v_199 = (self->v_198+1);
      if (r) {
        rightturn_count_St_1_Forward1 = 0;
      } else {
        rightturn_count_St_1_Forward1 = v_199;
      };
      v_196 = (leftforwardDetection==true);
      v_195 = (leftbackwardDetection==true);
      v_197 = (v_195&&v_196);
      if (v_197) {
        nr_St_1_Forward1 = true;
        ns_St_1_Forward1 = Line_follower__St_1_LeftTurn1;
      } else {
        nr_St_1_Forward1 = false;
        ns_St_1_Forward1 = Line_follower__St_1_Forward1;
      };
      _out->dir = dir_St_1_Forward1;
      flag = flag_St_1_Forward1;
      leftflag1 = leftflag1_St_1_Forward1;
      rightflag1 = rightflag1_St_1_Forward1;
      leftflag2 = leftflag2_St_1_Forward1;
      rightflag2 = rightflag2_St_1_Forward1;
      leftflag3 = leftflag3_St_1_Forward1;
      rightflag3 = rightflag3_St_1_Forward1;
      timer = timer_St_1_Forward1;
      timer1 = timer1_St_1_Forward1;
      rightturn_count = rightturn_count_St_1_Forward1;
      break;
    case Line_follower__St_1_LeftTurn1:
      rightturn_count_St_1_LeftTurn1 = self->rightturn_count_1;
      timer1_St_1_LeftTurn1 = self->timer1_1;
      rightflag3_St_1_LeftTurn1 = self->rightflag3_1;
      leftflag3_St_1_LeftTurn1 = self->leftflag3_1;
      rightflag2_St_1_LeftTurn1 = self->rightflag2_1;
      leftflag2_St_1_LeftTurn1 = self->leftflag2_1;
      rightflag1_St_1_LeftTurn1 = self->rightflag1_1;
      leftflag1_St_1_LeftTurn1 = self->leftflag1_1;
      v_194 = (self->v_193-1);
      if (r) {
        timer_St_1_LeftTurn1 = 33;
      } else {
        timer_St_1_LeftTurn1 = v_194;
      };
      flag_St_1_LeftTurn1 = true;
      v_r_St_1_LeftTurn1 = oasspeed;
      v_l_St_1_LeftTurn1 = oasspeed;
      dir_St_1_LeftTurn1 = 4;
      _out->dir = dir_St_1_LeftTurn1;
      flag = flag_St_1_LeftTurn1;
      leftflag1 = leftflag1_St_1_LeftTurn1;
      rightflag1 = rightflag1_St_1_LeftTurn1;
      leftflag2 = leftflag2_St_1_LeftTurn1;
      rightflag2 = rightflag2_St_1_LeftTurn1;
      leftflag3 = leftflag3_St_1_LeftTurn1;
      rightflag3 = rightflag3_St_1_LeftTurn1;
      timer = timer_St_1_LeftTurn1;
      v_192 = (timer<=0);
      if (v_192) {
        nr_St_1_LeftTurn1 = true;
        ns_St_1_LeftTurn1 = Line_follower__St_1_Move3;
      } else {
        nr_St_1_LeftTurn1 = false;
        ns_St_1_LeftTurn1 = Line_follower__St_1_LeftTurn1;
      };
      timer1 = timer1_St_1_LeftTurn1;
      rightturn_count = rightturn_count_St_1_LeftTurn1;
      break;
    case Line_follower__St_1_Move3:
      rightturn_count_St_1_Move3 = self->rightturn_count_1;
      timer1_St_1_Move3 = self->timer1_1;
      timer_St_1_Move3 = self->timer_1;
      rightflag3_St_1_Move3 = self->rightflag3_1;
      leftflag3_St_1_Move3 = self->leftflag3_1;
      rightflag2_St_1_Move3 = self->rightflag2_1;
      leftflag2_St_1_Move3 = self->leftflag2_1;
      rightflag1_St_1_Move3 = self->rightflag1_1;
      leftflag1_St_1_Move3 = self->leftflag1_1;
      flag_St_1_Move3 = true;
      v_r_St_1_Move3 = oasspeed;
      v_l_St_1_Move3 = oasspeed;
      dir_St_1_Move3 = 1;
      v_191 = (leftbackwardDetection==false);
      if (v_191) {
        nr_St_1_Move3 = true;
        ns_St_1_Move3 = Line_follower__St_1_Forward2;
      } else {
        nr_St_1_Move3 = false;
        ns_St_1_Move3 = Line_follower__St_1_Move3;
      };
      _out->dir = dir_St_1_Move3;
      flag = flag_St_1_Move3;
      leftflag1 = leftflag1_St_1_Move3;
      rightflag1 = rightflag1_St_1_Move3;
      leftflag2 = leftflag2_St_1_Move3;
      rightflag2 = rightflag2_St_1_Move3;
      leftflag3 = leftflag3_St_1_Move3;
      rightflag3 = rightflag3_St_1_Move3;
      timer = timer_St_1_Move3;
      timer1 = timer1_St_1_Move3;
      rightturn_count = rightturn_count_St_1_Move3;
      break;
    case Line_follower__St_1_Forward2:
      rightturn_count_St_1_Forward2 = self->rightturn_count_1;
      timer1_St_1_Forward2 = self->timer1_1;
      timer_St_1_Forward2 = self->timer_1;
      rightflag3_St_1_Forward2 = self->rightflag3_1;
      leftflag3_St_1_Forward2 = self->leftflag3_1;
      rightflag2_St_1_Forward2 = self->rightflag2_1;
      leftflag2_St_1_Forward2 = self->leftflag2_1;
      rightflag1_St_1_Forward2 = self->rightflag1_1;
      leftflag1_St_1_Forward2 = self->leftflag1_1;
      flag_St_1_Forward2 = true;
      v_r_St_1_Forward2 = oasspeed;
      v_l_St_1_Forward2 = oasspeed;
      dir_St_1_Forward2 = 1;
      v_190 = (leftbackwardDetection==true);
      if (v_190) {
        nr_St_1_Forward2 = true;
        ns_St_1_Forward2 = Line_follower__St_1_LeftTurn2;
      } else {
        nr_St_1_Forward2 = false;
        ns_St_1_Forward2 = Line_follower__St_1_Forward2;
      };
      _out->dir = dir_St_1_Forward2;
      flag = flag_St_1_Forward2;
      leftflag1 = leftflag1_St_1_Forward2;
      rightflag1 = rightflag1_St_1_Forward2;
      leftflag2 = leftflag2_St_1_Forward2;
      rightflag2 = rightflag2_St_1_Forward2;
      leftflag3 = leftflag3_St_1_Forward2;
      rightflag3 = rightflag3_St_1_Forward2;
      timer = timer_St_1_Forward2;
      timer1 = timer1_St_1_Forward2;
      rightturn_count = rightturn_count_St_1_Forward2;
      break;
    case Line_follower__St_1_LeftTurn2:
      rightturn_count_St_1_LeftTurn2 = self->rightturn_count_1;
      timer1_St_1_LeftTurn2 = self->timer1_1;
      rightflag3_St_1_LeftTurn2 = self->rightflag3_1;
      leftflag3_St_1_LeftTurn2 = self->leftflag3_1;
      rightflag2_St_1_LeftTurn2 = self->rightflag2_1;
      leftflag2_St_1_LeftTurn2 = self->leftflag2_1;
      rightflag1_St_1_LeftTurn2 = self->rightflag1_1;
      leftflag1_St_1_LeftTurn2 = self->leftflag1_1;
      v_189 = (self->v_188-1);
      if (r) {
        timer_St_1_LeftTurn2 = 30;
      } else {
        timer_St_1_LeftTurn2 = v_189;
      };
      flag_St_1_LeftTurn2 = true;
      v_r_St_1_LeftTurn2 = oasspeed;
      v_l_St_1_LeftTurn2 = oasspeed;
      dir_St_1_LeftTurn2 = 4;
      _out->dir = dir_St_1_LeftTurn2;
      flag = flag_St_1_LeftTurn2;
      leftflag1 = leftflag1_St_1_LeftTurn2;
      rightflag1 = rightflag1_St_1_LeftTurn2;
      leftflag2 = leftflag2_St_1_LeftTurn2;
      rightflag2 = rightflag2_St_1_LeftTurn2;
      leftflag3 = leftflag3_St_1_LeftTurn2;
      rightflag3 = rightflag3_St_1_LeftTurn2;
      timer = timer_St_1_LeftTurn2;
      v_187 = (timer<=0);
      if (v_187) {
        nr_St_1_LeftTurn2 = true;
        ns_St_1_LeftTurn2 = Line_follower__St_1_Move5;
      } else {
        nr_St_1_LeftTurn2 = false;
        ns_St_1_LeftTurn2 = Line_follower__St_1_LeftTurn2;
      };
      timer1 = timer1_St_1_LeftTurn2;
      rightturn_count = rightturn_count_St_1_LeftTurn2;
      break;
    case Line_follower__St_1_Move5:
      rightturn_count_St_1_Move5 = self->rightturn_count_1;
      timer1_St_1_Move5 = self->timer1_1;
      timer_St_1_Move5 = self->timer_1;
      rightflag3_St_1_Move5 = self->rightflag3_1;
      leftflag3_St_1_Move5 = self->leftflag3_1;
      rightflag2_St_1_Move5 = self->rightflag2_1;
      leftflag2_St_1_Move5 = self->leftflag2_1;
      rightflag1_St_1_Move5 = self->rightflag1_1;
      leftflag1_St_1_Move5 = self->leftflag1_1;
      flag_St_1_Move5 = true;
      v_r_St_1_Move5 = oasspeed;
      v_l_St_1_Move5 = oasspeed;
      dir_St_1_Move5 = 1;
      v_186 = (sen2<700);
      if (v_186) {
        nr_St_1_Move5 = true;
        ns_St_1_Move5 = Line_follower__St_1_RightTurn3;
      } else {
        nr_St_1_Move5 = false;
        ns_St_1_Move5 = Line_follower__St_1_Move5;
      };
      _out->dir = dir_St_1_Move5;
      flag = flag_St_1_Move5;
      leftflag1 = leftflag1_St_1_Move5;
      rightflag1 = rightflag1_St_1_Move5;
      leftflag2 = leftflag2_St_1_Move5;
      rightflag2 = rightflag2_St_1_Move5;
      leftflag3 = leftflag3_St_1_Move5;
      rightflag3 = rightflag3_St_1_Move5;
      timer = timer_St_1_Move5;
      timer1 = timer1_St_1_Move5;
      rightturn_count = rightturn_count_St_1_Move5;
      break;
    case Line_follower__St_1_RightTurn3:
      rightturn_count_St_1_RightTurn3 = self->rightturn_count_1;
      timer1_St_1_RightTurn3 = self->timer1_1;
      rightflag3_St_1_RightTurn3 = self->rightflag3_1;
      leftflag3_St_1_RightTurn3 = self->leftflag3_1;
      rightflag2_St_1_RightTurn3 = self->rightflag2_1;
      leftflag2_St_1_RightTurn3 = self->leftflag2_1;
      rightflag1_St_1_RightTurn3 = self->rightflag1_1;
      leftflag1_St_1_RightTurn3 = self->leftflag1_1;
      v_185 = (self->v_184-1);
      if (r) {
        timer_St_1_RightTurn3 = 80;
      } else {
        timer_St_1_RightTurn3 = v_185;
      };
      flag_St_1_RightTurn3 = true;
      v_r_St_1_RightTurn3 = oasspeed;
      v_l_St_1_RightTurn3 = oasspeed;
      dir_St_1_RightTurn3 = 5;
      _out->dir = dir_St_1_RightTurn3;
      flag = flag_St_1_RightTurn3;
      leftflag1 = leftflag1_St_1_RightTurn3;
      rightflag1 = rightflag1_St_1_RightTurn3;
      leftflag2 = leftflag2_St_1_RightTurn3;
      rightflag2 = rightflag2_St_1_RightTurn3;
      leftflag3 = leftflag3_St_1_RightTurn3;
      rightflag3 = rightflag3_St_1_RightTurn3;
      timer = timer_St_1_RightTurn3;
      v_183 = (timer<=0);
      if (v_183) {
        nr_St_1_RightTurn3 = true;
        ns_St_1_RightTurn3 = Line_follower__St_1_BlackRight;
      } else {
        nr_St_1_RightTurn3 = false;
        ns_St_1_RightTurn3 = Line_follower__St_1_RightTurn3;
      };
      timer1 = timer1_St_1_RightTurn3;
      rightturn_count = rightturn_count_St_1_RightTurn3;
      break;
    case Line_follower__St_1_ParkingDriftLeft:
      rightturn_count_St_1_ParkingDriftLeft = self->rightturn_count_1;
      timer1_St_1_ParkingDriftLeft = self->timer1_1;
      timer_St_1_ParkingDriftLeft = self->timer_1;
      rightflag3_St_1_ParkingDriftLeft = self->rightflag3_1;
      leftflag3_St_1_ParkingDriftLeft = self->leftflag3_1;
      rightflag2_St_1_ParkingDriftLeft = self->rightflag2_1;
      leftflag2_St_1_ParkingDriftLeft = self->leftflag2_1;
      rightflag1_St_1_ParkingDriftLeft = self->rightflag1_1;
      leftflag1_St_1_ParkingDriftLeft = self->leftflag1_1;
      flag_St_1_ParkingDriftLeft = true;
      dir_St_1_ParkingDriftLeft = 3;
      v_r_St_1_ParkingDriftLeft = (pspeed+pid);
      v_l_St_1_ParkingDriftLeft = 0;
      if (true) {
        v_180 = false;
      } else {
        v_180 = false;
      };
      if (b5) {
        v_182 = true;
      } else {
        v_182 = v_180;
      };
      if (b4) {
        nr_St_1_ParkingDriftLeft = true;
      } else {
        nr_St_1_ParkingDriftLeft = v_182;
      };
      if (true) {
        v_179 = Line_follower__St_1_ParkingStartFS;
      } else {
        v_179 = Line_follower__St_1_ParkingDriftLeft;
      };
      if (b5) {
        v_181 = Line_follower__St_1_ParkingDriftLeft;
      } else {
        v_181 = v_179;
      };
      if (b4) {
        ns_St_1_ParkingDriftLeft = Line_follower__St_1_ParkingDriftRight;
      } else {
        ns_St_1_ParkingDriftLeft = v_181;
      };
      _out->dir = dir_St_1_ParkingDriftLeft;
      flag = flag_St_1_ParkingDriftLeft;
      leftflag1 = leftflag1_St_1_ParkingDriftLeft;
      rightflag1 = rightflag1_St_1_ParkingDriftLeft;
      leftflag2 = leftflag2_St_1_ParkingDriftLeft;
      rightflag2 = rightflag2_St_1_ParkingDriftLeft;
      leftflag3 = leftflag3_St_1_ParkingDriftLeft;
      rightflag3 = rightflag3_St_1_ParkingDriftLeft;
      timer = timer_St_1_ParkingDriftLeft;
      timer1 = timer1_St_1_ParkingDriftLeft;
      rightturn_count = rightturn_count_St_1_ParkingDriftLeft;
      break;
    case Line_follower__St_1_ParkingDriftRight:
      rightturn_count_St_1_ParkingDriftRight = self->rightturn_count_1;
      timer1_St_1_ParkingDriftRight = self->timer1_1;
      timer_St_1_ParkingDriftRight = self->timer_1;
      rightflag3_St_1_ParkingDriftRight = self->rightflag3_1;
      leftflag3_St_1_ParkingDriftRight = self->leftflag3_1;
      rightflag2_St_1_ParkingDriftRight = self->rightflag2_1;
      leftflag2_St_1_ParkingDriftRight = self->leftflag2_1;
      rightflag1_St_1_ParkingDriftRight = self->rightflag1_1;
      leftflag1_St_1_ParkingDriftRight = self->leftflag1_1;
      flag_St_1_ParkingDriftRight = true;
      dir_St_1_ParkingDriftRight = 2;
      v_r_St_1_ParkingDriftRight = 0;
      v_l_St_1_ParkingDriftRight = (pspeed+pid);
      if (true) {
        v_176 = false;
      } else {
        v_176 = false;
      };
      if (b5) {
        v_178 = true;
      } else {
        v_178 = v_176;
      };
      if (b4) {
        nr_St_1_ParkingDriftRight = true;
      } else {
        nr_St_1_ParkingDriftRight = v_178;
      };
      if (true) {
        v_175 = Line_follower__St_1_ParkingStartFS;
      } else {
        v_175 = Line_follower__St_1_ParkingDriftRight;
      };
      if (b5) {
        v_177 = Line_follower__St_1_ParkingDriftLeft;
      } else {
        v_177 = v_175;
      };
      if (b4) {
        ns_St_1_ParkingDriftRight = Line_follower__St_1_ParkingDriftRight;
      } else {
        ns_St_1_ParkingDriftRight = v_177;
      };
      _out->dir = dir_St_1_ParkingDriftRight;
      flag = flag_St_1_ParkingDriftRight;
      leftflag1 = leftflag1_St_1_ParkingDriftRight;
      rightflag1 = rightflag1_St_1_ParkingDriftRight;
      leftflag2 = leftflag2_St_1_ParkingDriftRight;
      rightflag2 = rightflag2_St_1_ParkingDriftRight;
      leftflag3 = leftflag3_St_1_ParkingDriftRight;
      rightflag3 = rightflag3_St_1_ParkingDriftRight;
      timer = timer_St_1_ParkingDriftRight;
      timer1 = timer1_St_1_ParkingDriftRight;
      rightturn_count = rightturn_count_St_1_ParkingDriftRight;
      break;
    case Line_follower__St_1_ParkingDriftLeftSS:
      rightturn_count_St_1_ParkingDriftLeftSS = self->rightturn_count_1;
      timer1_St_1_ParkingDriftLeftSS = self->timer1_1;
      timer_St_1_ParkingDriftLeftSS = self->timer_1;
      rightflag3_St_1_ParkingDriftLeftSS = self->rightflag3_1;
      leftflag3_St_1_ParkingDriftLeftSS = self->leftflag3_1;
      rightflag2_St_1_ParkingDriftLeftSS = self->rightflag2_1;
      leftflag2_St_1_ParkingDriftLeftSS = self->leftflag2_1;
      rightflag1_St_1_ParkingDriftLeftSS = self->rightflag1_1;
      leftflag1_St_1_ParkingDriftLeftSS = self->leftflag1_1;
      flag_St_1_ParkingDriftLeftSS = true;
      dir_St_1_ParkingDriftLeftSS = 3;
      v_r_St_1_ParkingDriftLeftSS = (pspeed+pid);
      v_l_St_1_ParkingDriftLeftSS = 0;
      if (true) {
        v_172 = false;
      } else {
        v_172 = false;
      };
      if (b5) {
        v_174 = true;
      } else {
        v_174 = v_172;
      };
      if (b4) {
        nr_St_1_ParkingDriftLeftSS = true;
      } else {
        nr_St_1_ParkingDriftLeftSS = v_174;
      };
      if (true) {
        v_171 = Line_follower__St_1_ParkingStartSS;
      } else {
        v_171 = Line_follower__St_1_ParkingDriftLeftSS;
      };
      if (b5) {
        v_173 = Line_follower__St_1_ParkingDriftLeftSS;
      } else {
        v_173 = v_171;
      };
      if (b4) {
        ns_St_1_ParkingDriftLeftSS = Line_follower__St_1_ParkingDriftRightSS;
      } else {
        ns_St_1_ParkingDriftLeftSS = v_173;
      };
      _out->dir = dir_St_1_ParkingDriftLeftSS;
      flag = flag_St_1_ParkingDriftLeftSS;
      leftflag1 = leftflag1_St_1_ParkingDriftLeftSS;
      rightflag1 = rightflag1_St_1_ParkingDriftLeftSS;
      leftflag2 = leftflag2_St_1_ParkingDriftLeftSS;
      rightflag2 = rightflag2_St_1_ParkingDriftLeftSS;
      leftflag3 = leftflag3_St_1_ParkingDriftLeftSS;
      rightflag3 = rightflag3_St_1_ParkingDriftLeftSS;
      timer = timer_St_1_ParkingDriftLeftSS;
      timer1 = timer1_St_1_ParkingDriftLeftSS;
      rightturn_count = rightturn_count_St_1_ParkingDriftLeftSS;
      break;
    case Line_follower__St_1_ParkingDriftRightSS:
      rightturn_count_St_1_ParkingDriftRightSS = self->rightturn_count_1;
      timer1_St_1_ParkingDriftRightSS = self->timer1_1;
      timer_St_1_ParkingDriftRightSS = self->timer_1;
      rightflag3_St_1_ParkingDriftRightSS = self->rightflag3_1;
      leftflag3_St_1_ParkingDriftRightSS = self->leftflag3_1;
      rightflag2_St_1_ParkingDriftRightSS = self->rightflag2_1;
      leftflag2_St_1_ParkingDriftRightSS = self->leftflag2_1;
      rightflag1_St_1_ParkingDriftRightSS = self->rightflag1_1;
      leftflag1_St_1_ParkingDriftRightSS = self->leftflag1_1;
      flag_St_1_ParkingDriftRightSS = true;
      dir_St_1_ParkingDriftRightSS = 2;
      v_r_St_1_ParkingDriftRightSS = 0;
      v_l_St_1_ParkingDriftRightSS = (pspeed+pid);
      if (true) {
        v_168 = false;
      } else {
        v_168 = false;
      };
      if (b5) {
        v_170 = true;
      } else {
        v_170 = v_168;
      };
      if (b4) {
        nr_St_1_ParkingDriftRightSS = true;
      } else {
        nr_St_1_ParkingDriftRightSS = v_170;
      };
      if (true) {
        v_167 = Line_follower__St_1_ParkingStartSS;
      } else {
        v_167 = Line_follower__St_1_ParkingDriftRightSS;
      };
      if (b5) {
        v_169 = Line_follower__St_1_ParkingDriftLeftSS;
      } else {
        v_169 = v_167;
      };
      if (b4) {
        ns_St_1_ParkingDriftRightSS = Line_follower__St_1_ParkingDriftRightSS;
      } else {
        ns_St_1_ParkingDriftRightSS = v_169;
      };
      _out->dir = dir_St_1_ParkingDriftRightSS;
      flag = flag_St_1_ParkingDriftRightSS;
      leftflag1 = leftflag1_St_1_ParkingDriftRightSS;
      rightflag1 = rightflag1_St_1_ParkingDriftRightSS;
      leftflag2 = leftflag2_St_1_ParkingDriftRightSS;
      rightflag2 = rightflag2_St_1_ParkingDriftRightSS;
      leftflag3 = leftflag3_St_1_ParkingDriftRightSS;
      rightflag3 = rightflag3_St_1_ParkingDriftRightSS;
      timer = timer_St_1_ParkingDriftRightSS;
      timer1 = timer1_St_1_ParkingDriftRightSS;
      rightturn_count = rightturn_count_St_1_ParkingDriftRightSS;
      break;
    case Line_follower__St_1_ParkingDriftLeftTS:
      rightturn_count_St_1_ParkingDriftLeftTS = self->rightturn_count_1;
      timer1_St_1_ParkingDriftLeftTS = self->timer1_1;
      timer_St_1_ParkingDriftLeftTS = self->timer_1;
      rightflag3_St_1_ParkingDriftLeftTS = self->rightflag3_1;
      leftflag3_St_1_ParkingDriftLeftTS = self->leftflag3_1;
      rightflag2_St_1_ParkingDriftLeftTS = self->rightflag2_1;
      leftflag2_St_1_ParkingDriftLeftTS = self->leftflag2_1;
      rightflag1_St_1_ParkingDriftLeftTS = self->rightflag1_1;
      leftflag1_St_1_ParkingDriftLeftTS = self->leftflag1_1;
      flag_St_1_ParkingDriftLeftTS = true;
      dir_St_1_ParkingDriftLeftTS = 3;
      v_r_St_1_ParkingDriftLeftTS = (pspeed+pid);
      v_l_St_1_ParkingDriftLeftTS = 0;
      if (true) {
        v_164 = false;
      } else {
        v_164 = false;
      };
      if (b5) {
        v_166 = true;
      } else {
        v_166 = v_164;
      };
      if (b4) {
        nr_St_1_ParkingDriftLeftTS = true;
      } else {
        nr_St_1_ParkingDriftLeftTS = v_166;
      };
      if (true) {
        v_163 = Line_follower__St_1_ParkingStartTS;
      } else {
        v_163 = Line_follower__St_1_ParkingDriftLeftTS;
      };
      if (b5) {
        v_165 = Line_follower__St_1_ParkingDriftLeftTS;
      } else {
        v_165 = v_163;
      };
      if (b4) {
        ns_St_1_ParkingDriftLeftTS = Line_follower__St_1_ParkingDriftRightTS;
      } else {
        ns_St_1_ParkingDriftLeftTS = v_165;
      };
      _out->dir = dir_St_1_ParkingDriftLeftTS;
      flag = flag_St_1_ParkingDriftLeftTS;
      leftflag1 = leftflag1_St_1_ParkingDriftLeftTS;
      rightflag1 = rightflag1_St_1_ParkingDriftLeftTS;
      leftflag2 = leftflag2_St_1_ParkingDriftLeftTS;
      rightflag2 = rightflag2_St_1_ParkingDriftLeftTS;
      leftflag3 = leftflag3_St_1_ParkingDriftLeftTS;
      rightflag3 = rightflag3_St_1_ParkingDriftLeftTS;
      timer = timer_St_1_ParkingDriftLeftTS;
      timer1 = timer1_St_1_ParkingDriftLeftTS;
      rightturn_count = rightturn_count_St_1_ParkingDriftLeftTS;
      break;
    case Line_follower__St_1_ParkingDriftRightTS:
      rightturn_count_St_1_ParkingDriftRightTS = self->rightturn_count_1;
      timer1_St_1_ParkingDriftRightTS = self->timer1_1;
      timer_St_1_ParkingDriftRightTS = self->timer_1;
      rightflag3_St_1_ParkingDriftRightTS = self->rightflag3_1;
      leftflag3_St_1_ParkingDriftRightTS = self->leftflag3_1;
      rightflag2_St_1_ParkingDriftRightTS = self->rightflag2_1;
      leftflag2_St_1_ParkingDriftRightTS = self->leftflag2_1;
      rightflag1_St_1_ParkingDriftRightTS = self->rightflag1_1;
      leftflag1_St_1_ParkingDriftRightTS = self->leftflag1_1;
      flag_St_1_ParkingDriftRightTS = true;
      dir_St_1_ParkingDriftRightTS = 2;
      v_r_St_1_ParkingDriftRightTS = 0;
      v_l_St_1_ParkingDriftRightTS = (pspeed+pid);
      if (true) {
        v_160 = false;
      } else {
        v_160 = false;
      };
      if (b5) {
        v_162 = true;
      } else {
        v_162 = v_160;
      };
      if (b4) {
        nr_St_1_ParkingDriftRightTS = true;
      } else {
        nr_St_1_ParkingDriftRightTS = v_162;
      };
      if (true) {
        v_159 = Line_follower__St_1_ParkingStartTS;
      } else {
        v_159 = Line_follower__St_1_ParkingDriftRightTS;
      };
      if (b5) {
        v_161 = Line_follower__St_1_ParkingDriftLeftTS;
      } else {
        v_161 = v_159;
      };
      if (b4) {
        ns_St_1_ParkingDriftRightTS = Line_follower__St_1_ParkingDriftRightTS;
      } else {
        ns_St_1_ParkingDriftRightTS = v_161;
      };
      _out->dir = dir_St_1_ParkingDriftRightTS;
      flag = flag_St_1_ParkingDriftRightTS;
      leftflag1 = leftflag1_St_1_ParkingDriftRightTS;
      rightflag1 = rightflag1_St_1_ParkingDriftRightTS;
      leftflag2 = leftflag2_St_1_ParkingDriftRightTS;
      rightflag2 = rightflag2_St_1_ParkingDriftRightTS;
      leftflag3 = leftflag3_St_1_ParkingDriftRightTS;
      rightflag3 = rightflag3_St_1_ParkingDriftRightTS;
      timer = timer_St_1_ParkingDriftRightTS;
      timer1 = timer1_St_1_ParkingDriftRightTS;
      rightturn_count = rightturn_count_St_1_ParkingDriftRightTS;
      break;
    case Line_follower__St_1_ParkingDelay:
      rightturn_count_St_1_ParkingDelay = self->rightturn_count_1;
      timer1_St_1_ParkingDelay = self->timer1_1;
      rightflag3_St_1_ParkingDelay = self->rightflag3_1;
      leftflag3_St_1_ParkingDelay = self->leftflag3_1;
      rightflag2_St_1_ParkingDelay = self->rightflag2_1;
      leftflag2_St_1_ParkingDelay = self->leftflag2_1;
      rightflag1_St_1_ParkingDelay = self->rightflag1_1;
      leftflag1_St_1_ParkingDelay = self->leftflag1_1;
      v_158 = (self->v_157-1);
      if (r) {
        timer_St_1_ParkingDelay = 50;
      } else {
        timer_St_1_ParkingDelay = v_158;
      };
      flag_St_1_ParkingDelay = true;
      v_r_St_1_ParkingDelay = 0;
      v_l_St_1_ParkingDelay = 0;
      dir_St_1_ParkingDelay = 0;
      _out->dir = dir_St_1_ParkingDelay;
      flag = flag_St_1_ParkingDelay;
      leftflag1 = leftflag1_St_1_ParkingDelay;
      rightflag1 = rightflag1_St_1_ParkingDelay;
      leftflag2 = leftflag2_St_1_ParkingDelay;
      rightflag2 = rightflag2_St_1_ParkingDelay;
      leftflag3 = leftflag3_St_1_ParkingDelay;
      rightflag3 = rightflag3_St_1_ParkingDelay;
      timer = timer_St_1_ParkingDelay;
      v_156 = (timer<=0);
      if (v_156) {
        nr_St_1_ParkingDelay = true;
        ns_St_1_ParkingDelay = Line_follower__St_1_Parking;
      } else {
        nr_St_1_ParkingDelay = false;
        ns_St_1_ParkingDelay = Line_follower__St_1_ParkingDelay;
      };
      timer1 = timer1_St_1_ParkingDelay;
      rightturn_count = rightturn_count_St_1_ParkingDelay;
      break;
    case Line_follower__St_1_Parking:
      rightturn_count_St_1_Parking = self->rightturn_count_1;
      timer1_St_1_Parking = self->timer1_1;
      timer_St_1_Parking = self->timer_1;
      rightflag3_St_1_Parking = self->rightflag3_1;
      leftflag3_St_1_Parking = self->leftflag3_1;
      rightflag2_St_1_Parking = self->rightflag2_1;
      leftflag2_St_1_Parking = self->leftflag2_1;
      rightflag1_St_1_Parking = self->rightflag1_1;
      leftflag1_St_1_Parking = self->leftflag1_1;
      flag_St_1_Parking = true;
      v_r_St_1_Parking = 0;
      v_l_St_1_Parking = 0;
      dir_St_1_Parking = 0;
      if (true) {
        v_155 = true;
      } else {
        v_155 = false;
      };
      if (true) {
        v_154 = Line_follower__St_1_FirstleftParking;
      } else {
        v_154 = Line_follower__St_1_Parking;
      };
      v_153 = (rightforwardDetection==false);
      if (v_153) {
        nr_St_1_Parking = true;
        ns_St_1_Parking = Line_follower__St_1_ParkingStartFS;
      } else {
        nr_St_1_Parking = v_155;
        ns_St_1_Parking = v_154;
      };
      _out->dir = dir_St_1_Parking;
      flag = flag_St_1_Parking;
      leftflag1 = leftflag1_St_1_Parking;
      rightflag1 = rightflag1_St_1_Parking;
      leftflag2 = leftflag2_St_1_Parking;
      rightflag2 = rightflag2_St_1_Parking;
      leftflag3 = leftflag3_St_1_Parking;
      rightflag3 = rightflag3_St_1_Parking;
      timer = timer_St_1_Parking;
      timer1 = timer1_St_1_Parking;
      rightturn_count = rightturn_count_St_1_Parking;
      break;
    case Line_follower__St_1_FirstleftParking:
      rightturn_count_St_1_FirstleftParking = self->rightturn_count_1;
      timer1_St_1_FirstleftParking = self->timer1_1;
      timer_St_1_FirstleftParking = self->timer_1;
      rightflag3_St_1_FirstleftParking = self->rightflag3_1;
      leftflag3_St_1_FirstleftParking = self->leftflag3_1;
      rightflag2_St_1_FirstleftParking = self->rightflag2_1;
      leftflag2_St_1_FirstleftParking = self->leftflag2_1;
      rightflag1_St_1_FirstleftParking = self->rightflag1_1;
      leftflag1_St_1_FirstleftParking = self->leftflag1_1;
      flag_St_1_FirstleftParking = true;
      v_r_St_1_FirstleftParking = 0;
      v_l_St_1_FirstleftParking = (pspeed+pid);
      dir_St_1_FirstleftParking = 4;
      if (switch_condition) {
        nr_St_1_FirstleftParking = true;
        ns_St_1_FirstleftParking = Line_follower__St_1_Forwardoneparking;
      } else {
        nr_St_1_FirstleftParking = false;
        ns_St_1_FirstleftParking = Line_follower__St_1_FirstleftParking;
      };
      _out->dir = dir_St_1_FirstleftParking;
      flag = flag_St_1_FirstleftParking;
      leftflag1 = leftflag1_St_1_FirstleftParking;
      rightflag1 = rightflag1_St_1_FirstleftParking;
      leftflag2 = leftflag2_St_1_FirstleftParking;
      rightflag2 = rightflag2_St_1_FirstleftParking;
      leftflag3 = leftflag3_St_1_FirstleftParking;
      rightflag3 = rightflag3_St_1_FirstleftParking;
      timer = timer_St_1_FirstleftParking;
      timer1 = timer1_St_1_FirstleftParking;
      rightturn_count = rightturn_count_St_1_FirstleftParking;
      break;
    case Line_follower__St_1_Forwardoneparking:
      rightturn_count_St_1_Forwardoneparking = self->rightturn_count_1;
      timer1_St_1_Forwardoneparking = self->timer1_1;
      timer_St_1_Forwardoneparking = self->timer_1;
      rightflag3_St_1_Forwardoneparking = self->rightflag3_1;
      leftflag3_St_1_Forwardoneparking = self->leftflag3_1;
      rightflag2_St_1_Forwardoneparking = self->rightflag2_1;
      leftflag2_St_1_Forwardoneparking = self->leftflag2_1;
      rightflag1_St_1_Forwardoneparking = self->rightflag1_1;
      leftflag1_St_1_Forwardoneparking = self->leftflag1_1;
      flag_St_1_Forwardoneparking = true;
      v_r_St_1_Forwardoneparking = (pspeed-10);
      v_l_St_1_Forwardoneparking = (pspeed-10);
      dir_St_1_Forwardoneparking = 1;
      if (blacknodedetected) {
        v_150 = true;
      } else {
        v_150 = false;
      };
      if (b5) {
        v_152 = true;
      } else {
        v_152 = v_150;
      };
      if (b4) {
        nr_St_1_Forwardoneparking = true;
      } else {
        nr_St_1_Forwardoneparking = v_152;
      };
      if (blacknodedetected) {
        v_149 = Line_follower__St_1_ParkingDelay;
      } else {
        v_149 = Line_follower__St_1_Forwardoneparking;
      };
      if (b5) {
        v_151 = Line_follower__St_1_PreParkingDriftLeft;
      } else {
        v_151 = v_149;
      };
      if (b4) {
        ns_St_1_Forwardoneparking = Line_follower__St_1_PreParkingDriftRight;
      } else {
        ns_St_1_Forwardoneparking = v_151;
      };
      _out->dir = dir_St_1_Forwardoneparking;
      flag = flag_St_1_Forwardoneparking;
      leftflag1 = leftflag1_St_1_Forwardoneparking;
      rightflag1 = rightflag1_St_1_Forwardoneparking;
      leftflag2 = leftflag2_St_1_Forwardoneparking;
      rightflag2 = rightflag2_St_1_Forwardoneparking;
      leftflag3 = leftflag3_St_1_Forwardoneparking;
      rightflag3 = rightflag3_St_1_Forwardoneparking;
      timer = timer_St_1_Forwardoneparking;
      timer1 = timer1_St_1_Forwardoneparking;
      rightturn_count = rightturn_count_St_1_Forwardoneparking;
      break;
    case Line_follower__St_1_PreParkingDriftLeft:
      rightturn_count_St_1_PreParkingDriftLeft = self->rightturn_count_1;
      timer1_St_1_PreParkingDriftLeft = self->timer1_1;
      timer_St_1_PreParkingDriftLeft = self->timer_1;
      rightflag3_St_1_PreParkingDriftLeft = self->rightflag3_1;
      leftflag3_St_1_PreParkingDriftLeft = self->leftflag3_1;
      rightflag2_St_1_PreParkingDriftLeft = self->rightflag2_1;
      leftflag2_St_1_PreParkingDriftLeft = self->leftflag2_1;
      rightflag1_St_1_PreParkingDriftLeft = self->rightflag1_1;
      leftflag1_St_1_PreParkingDriftLeft = self->leftflag1_1;
      flag_St_1_PreParkingDriftLeft = true;
      dir_St_1_PreParkingDriftLeft = 3;
      v_r_St_1_PreParkingDriftLeft = (pspeed+pid);
      v_l_St_1_PreParkingDriftLeft = 0;
      if (true) {
        v_146 = false;
      } else {
        v_146 = false;
      };
      if (b5) {
        v_148 = true;
      } else {
        v_148 = v_146;
      };
      if (b4) {
        nr_St_1_PreParkingDriftLeft = true;
      } else {
        nr_St_1_PreParkingDriftLeft = v_148;
      };
      if (true) {
        v_145 = Line_follower__St_1_Forwardoneparking;
      } else {
        v_145 = Line_follower__St_1_PreParkingDriftLeft;
      };
      if (b5) {
        v_147 = Line_follower__St_1_PreParkingDriftLeft;
      } else {
        v_147 = v_145;
      };
      if (b4) {
        ns_St_1_PreParkingDriftLeft = Line_follower__St_1_PreParkingDriftRight;
      } else {
        ns_St_1_PreParkingDriftLeft = v_147;
      };
      _out->dir = dir_St_1_PreParkingDriftLeft;
      flag = flag_St_1_PreParkingDriftLeft;
      leftflag1 = leftflag1_St_1_PreParkingDriftLeft;
      rightflag1 = rightflag1_St_1_PreParkingDriftLeft;
      leftflag2 = leftflag2_St_1_PreParkingDriftLeft;
      rightflag2 = rightflag2_St_1_PreParkingDriftLeft;
      leftflag3 = leftflag3_St_1_PreParkingDriftLeft;
      rightflag3 = rightflag3_St_1_PreParkingDriftLeft;
      timer = timer_St_1_PreParkingDriftLeft;
      timer1 = timer1_St_1_PreParkingDriftLeft;
      rightturn_count = rightturn_count_St_1_PreParkingDriftLeft;
      break;
    case Line_follower__St_1_PreParkingDriftRight:
      rightturn_count_St_1_PreParkingDriftRight = self->rightturn_count_1;
      timer1_St_1_PreParkingDriftRight = self->timer1_1;
      timer_St_1_PreParkingDriftRight = self->timer_1;
      rightflag3_St_1_PreParkingDriftRight = self->rightflag3_1;
      leftflag3_St_1_PreParkingDriftRight = self->leftflag3_1;
      rightflag2_St_1_PreParkingDriftRight = self->rightflag2_1;
      leftflag2_St_1_PreParkingDriftRight = self->leftflag2_1;
      rightflag1_St_1_PreParkingDriftRight = self->rightflag1_1;
      leftflag1_St_1_PreParkingDriftRight = self->leftflag1_1;
      flag_St_1_PreParkingDriftRight = true;
      dir_St_1_PreParkingDriftRight = 2;
      v_r_St_1_PreParkingDriftRight = 0;
      v_l_St_1_PreParkingDriftRight = (pspeed+pid);
      if (true) {
        v_142 = false;
      } else {
        v_142 = false;
      };
      if (b5) {
        v_144 = true;
      } else {
        v_144 = v_142;
      };
      if (b4) {
        nr_St_1_PreParkingDriftRight = true;
      } else {
        nr_St_1_PreParkingDriftRight = v_144;
      };
      if (true) {
        v_141 = Line_follower__St_1_Forwardoneparking;
      } else {
        v_141 = Line_follower__St_1_PreParkingDriftRight;
      };
      if (b5) {
        v_143 = Line_follower__St_1_PreParkingDriftLeft;
      } else {
        v_143 = v_141;
      };
      if (b4) {
        ns_St_1_PreParkingDriftRight = Line_follower__St_1_PreParkingDriftRight;
      } else {
        ns_St_1_PreParkingDriftRight = v_143;
      };
      _out->dir = dir_St_1_PreParkingDriftRight;
      flag = flag_St_1_PreParkingDriftRight;
      leftflag1 = leftflag1_St_1_PreParkingDriftRight;
      rightflag1 = rightflag1_St_1_PreParkingDriftRight;
      leftflag2 = leftflag2_St_1_PreParkingDriftRight;
      rightflag2 = rightflag2_St_1_PreParkingDriftRight;
      leftflag3 = leftflag3_St_1_PreParkingDriftRight;
      rightflag3 = rightflag3_St_1_PreParkingDriftRight;
      timer = timer_St_1_PreParkingDriftRight;
      timer1 = timer1_St_1_PreParkingDriftRight;
      rightturn_count = rightturn_count_St_1_PreParkingDriftRight;
      break;
    case Line_follower__St_1_ParkingStartFS:
      rightturn_count_St_1_ParkingStartFS = self->rightturn_count_1;
      timer_St_1_ParkingStartFS = self->timer_1;
      rightflag3_St_1_ParkingStartFS = self->rightflag3_1;
      leftflag3_St_1_ParkingStartFS = self->leftflag3_1;
      rightflag2_St_1_ParkingStartFS = self->rightflag2_1;
      leftflag2_St_1_ParkingStartFS = self->leftflag2_1;
      v_140 = (self->v_139-1);
      if (r) {
        timer1_St_1_ParkingStartFS = 450;
      } else {
        timer1_St_1_ParkingStartFS = v_140;
      };
      v_138 = (self->rightflag1_1+1);
      v_136 = (rightforwardDetection==false);
      v_135 = (rightbackwardDetection==false);
      v_137 = (v_135||v_136);
      if (v_137) {
        rightflag1_St_1_ParkingStartFS = v_138;
      } else {
        rightflag1_St_1_ParkingStartFS = self->rightflag1_1;
      };
      v_134 = (self->leftflag1_1+1);
      v_132 = (leftforwardDetection==false);
      v_131 = (leftbackwardDetection==false);
      v_133 = (v_131||v_132);
      if (v_133) {
        leftflag1_St_1_ParkingStartFS = v_134;
      } else {
        leftflag1_St_1_ParkingStartFS = self->leftflag1_1;
      };
      dir_St_1_ParkingStartFS = 1;
      flag_St_1_ParkingStartFS = true;
      v_r_St_1_ParkingStartFS = pspeed;
      v_l_St_1_ParkingStartFS = pspeed;
      if (b5) {
        v_124 = true;
      } else {
        v_124 = false;
      };
      if (b4) {
        v_126 = true;
      } else {
        v_126 = v_124;
      };
      if (b5) {
        v_123 = Line_follower__St_1_ParkingDriftLeft;
      } else {
        v_123 = Line_follower__St_1_ParkingStartFS;
      };
      if (b4) {
        v_125 = Line_follower__St_1_ParkingDriftRight;
      } else {
        v_125 = v_123;
      };
      _out->dir = dir_St_1_ParkingStartFS;
      flag = flag_St_1_ParkingStartFS;
      leftflag1 = leftflag1_St_1_ParkingStartFS;
      v_119 = (leftflag1>0);
      v_113 = (leftflag1==0);
      rightflag1 = rightflag1_St_1_ParkingStartFS;
      v_121 = (rightflag1>0);
      v_116 = (rightflag1==0);
      leftflag2 = leftflag2_St_1_ParkingStartFS;
      rightflag2 = rightflag2_St_1_ParkingStartFS;
      leftflag3 = leftflag3_St_1_ParkingStartFS;
      rightflag3 = rightflag3_St_1_ParkingStartFS;
      timer = timer_St_1_ParkingStartFS;
      timer1 = timer1_St_1_ParkingStartFS;
      v_118 = (timer1<=0);
      v_120 = (v_118&&v_119);
      v_122 = (v_120&&v_121);
      if (v_122) {
        v_128 = true;
        v_127 = Line_follower__St_1_DelayP1;
      } else {
        v_128 = v_126;
        v_127 = v_125;
      };
      v_115 = (timer1<=0);
      v_117 = (v_115&&v_116);
      if (v_117) {
        v_130 = true;
        v_129 = Line_follower__St_1_ParkrightBackward;
      } else {
        v_130 = v_128;
        v_129 = v_127;
      };
      v_112 = (timer1<=0);
      v_114 = (v_112&&v_113);
      if (v_114) {
        nr_St_1_ParkingStartFS = true;
        ns_St_1_ParkingStartFS = Line_follower__St_1_ParkleftBackward;
      } else {
        nr_St_1_ParkingStartFS = v_130;
        ns_St_1_ParkingStartFS = v_129;
      };
      rightturn_count = rightturn_count_St_1_ParkingStartFS;
      break;
    case Line_follower__St_1_DelayP1:
      rightturn_count_St_1_DelayP1 = self->rightturn_count_1;
      timer_St_1_DelayP1 = self->timer_1;
      rightflag3_St_1_DelayP1 = self->rightflag3_1;
      leftflag3_St_1_DelayP1 = self->leftflag3_1;
      rightflag2_St_1_DelayP1 = self->rightflag2_1;
      leftflag2_St_1_DelayP1 = self->leftflag2_1;
      rightflag1_St_1_DelayP1 = self->rightflag1_1;
      leftflag1_St_1_DelayP1 = self->leftflag1_1;
      v_111 = (self->v_110-1);
      if (r) {
        timer1_St_1_DelayP1 = 5;
      } else {
        timer1_St_1_DelayP1 = v_111;
      };
      flag_St_1_DelayP1 = true;
      v_r_St_1_DelayP1 = 0;
      v_l_St_1_DelayP1 = 0;
      dir_St_1_DelayP1 = 0;
      _out->dir = dir_St_1_DelayP1;
      flag = flag_St_1_DelayP1;
      leftflag1 = leftflag1_St_1_DelayP1;
      rightflag1 = rightflag1_St_1_DelayP1;
      leftflag2 = leftflag2_St_1_DelayP1;
      rightflag2 = rightflag2_St_1_DelayP1;
      leftflag3 = leftflag3_St_1_DelayP1;
      rightflag3 = rightflag3_St_1_DelayP1;
      timer = timer_St_1_DelayP1;
      timer1 = timer1_St_1_DelayP1;
      v_109 = (timer1<=0);
      if (v_109) {
        nr_St_1_DelayP1 = true;
        ns_St_1_DelayP1 = Line_follower__St_1_ParkingStartSS;
      } else {
        nr_St_1_DelayP1 = false;
        ns_St_1_DelayP1 = Line_follower__St_1_DelayP1;
      };
      rightturn_count = rightturn_count_St_1_DelayP1;
      break;
    case Line_follower__St_1_ParkingStartSS:
      rightturn_count_St_1_ParkingStartSS = self->rightturn_count_1;
      timer_St_1_ParkingStartSS = self->timer_1;
      rightflag3_St_1_ParkingStartSS = self->rightflag3_1;
      leftflag3_St_1_ParkingStartSS = self->leftflag3_1;
      rightflag1_St_1_ParkingStartSS = self->rightflag1_1;
      leftflag1_St_1_ParkingStartSS = self->leftflag1_1;
      v_108 = (self->v_107-1);
      if (r) {
        timer1_St_1_ParkingStartSS = 450;
      } else {
        timer1_St_1_ParkingStartSS = v_108;
      };
      v_106 = (self->rightflag2_1+1);
      v_104 = (rightforwardDetection==false);
      v_103 = (rightbackwardDetection==false);
      v_105 = (v_103||v_104);
      if (v_105) {
        rightflag2_St_1_ParkingStartSS = v_106;
      } else {
        rightflag2_St_1_ParkingStartSS = self->rightflag2_1;
      };
      v_102 = (self->leftflag2_1+1);
      v_100 = (leftforwardDetection==false);
      v_99 = (leftbackwardDetection==false);
      v_101 = (v_99||v_100);
      if (v_101) {
        leftflag2_St_1_ParkingStartSS = v_102;
      } else {
        leftflag2_St_1_ParkingStartSS = self->leftflag2_1;
      };
      dir_St_1_ParkingStartSS = 1;
      flag_St_1_ParkingStartSS = true;
      v_r_St_1_ParkingStartSS = pspeed;
      v_l_St_1_ParkingStartSS = pspeed;
      if (b5) {
        v_92 = true;
      } else {
        v_92 = false;
      };
      if (b4) {
        v_94 = true;
      } else {
        v_94 = v_92;
      };
      if (b5) {
        v_91 = Line_follower__St_1_ParkingDriftLeftSS;
      } else {
        v_91 = Line_follower__St_1_ParkingStartSS;
      };
      if (b4) {
        v_93 = Line_follower__St_1_ParkingDriftRightSS;
      } else {
        v_93 = v_91;
      };
      _out->dir = dir_St_1_ParkingStartSS;
      flag = flag_St_1_ParkingStartSS;
      leftflag1 = leftflag1_St_1_ParkingStartSS;
      rightflag1 = rightflag1_St_1_ParkingStartSS;
      leftflag2 = leftflag2_St_1_ParkingStartSS;
      v_87 = (leftflag2>0);
      v_81 = (leftflag2==0);
      rightflag2 = rightflag2_St_1_ParkingStartSS;
      v_89 = (rightflag2>0);
      v_84 = (rightflag2==0);
      leftflag3 = leftflag3_St_1_ParkingStartSS;
      rightflag3 = rightflag3_St_1_ParkingStartSS;
      timer = timer_St_1_ParkingStartSS;
      timer1 = timer1_St_1_ParkingStartSS;
      v_86 = (timer1<=0);
      v_88 = (v_86&&v_87);
      v_90 = (v_88&&v_89);
      if (v_90) {
        v_96 = true;
        v_95 = Line_follower__St_1_DelayP2;
      } else {
        v_96 = v_94;
        v_95 = v_93;
      };
      v_83 = (timer1<=0);
      v_85 = (v_83&&v_84);
      if (v_85) {
        v_98 = true;
        v_97 = Line_follower__St_1_ParkrightBackward;
      } else {
        v_98 = v_96;
        v_97 = v_95;
      };
      v_80 = (timer1<=0);
      v_82 = (v_80&&v_81);
      if (v_82) {
        nr_St_1_ParkingStartSS = true;
        ns_St_1_ParkingStartSS = Line_follower__St_1_ParkleftBackward;
      } else {
        nr_St_1_ParkingStartSS = v_98;
        ns_St_1_ParkingStartSS = v_97;
      };
      rightturn_count = rightturn_count_St_1_ParkingStartSS;
      break;
    case Line_follower__St_1_DelayP2:
      rightturn_count_St_1_DelayP2 = self->rightturn_count_1;
      timer_St_1_DelayP2 = self->timer_1;
      rightflag3_St_1_DelayP2 = self->rightflag3_1;
      leftflag3_St_1_DelayP2 = self->leftflag3_1;
      rightflag2_St_1_DelayP2 = self->rightflag2_1;
      leftflag2_St_1_DelayP2 = self->leftflag2_1;
      rightflag1_St_1_DelayP2 = self->rightflag1_1;
      leftflag1_St_1_DelayP2 = self->leftflag1_1;
      v_79 = (self->v_78-1);
      if (r) {
        timer1_St_1_DelayP2 = 5;
      } else {
        timer1_St_1_DelayP2 = v_79;
      };
      flag_St_1_DelayP2 = true;
      v_r_St_1_DelayP2 = 0;
      v_l_St_1_DelayP2 = 0;
      dir_St_1_DelayP2 = 0;
      _out->dir = dir_St_1_DelayP2;
      flag = flag_St_1_DelayP2;
      leftflag1 = leftflag1_St_1_DelayP2;
      rightflag1 = rightflag1_St_1_DelayP2;
      leftflag2 = leftflag2_St_1_DelayP2;
      rightflag2 = rightflag2_St_1_DelayP2;
      leftflag3 = leftflag3_St_1_DelayP2;
      rightflag3 = rightflag3_St_1_DelayP2;
      timer = timer_St_1_DelayP2;
      timer1 = timer1_St_1_DelayP2;
      v_77 = (timer1<=0);
      if (v_77) {
        nr_St_1_DelayP2 = true;
        ns_St_1_DelayP2 = Line_follower__St_1_ParkingStartTS;
      } else {
        nr_St_1_DelayP2 = false;
        ns_St_1_DelayP2 = Line_follower__St_1_DelayP2;
      };
      rightturn_count = rightturn_count_St_1_DelayP2;
      break;
    case Line_follower__St_1_ParkingStartTS:
      rightturn_count_St_1_ParkingStartTS = self->rightturn_count_1;
      timer_St_1_ParkingStartTS = self->timer_1;
      rightflag2_St_1_ParkingStartTS = self->rightflag2_1;
      leftflag2_St_1_ParkingStartTS = self->leftflag2_1;
      rightflag1_St_1_ParkingStartTS = self->rightflag1_1;
      leftflag1_St_1_ParkingStartTS = self->leftflag1_1;
      v_76 = (self->v_75-1);
      if (r) {
        timer1_St_1_ParkingStartTS = 450;
      } else {
        timer1_St_1_ParkingStartTS = v_76;
      };
      v_74 = (self->rightflag3_1+1);
      v_72 = (rightforwardDetection==false);
      v_71 = (rightbackwardDetection==false);
      v_73 = (v_71||v_72);
      if (v_73) {
        rightflag3_St_1_ParkingStartTS = v_74;
      } else {
        rightflag3_St_1_ParkingStartTS = self->rightflag3_1;
      };
      v_70 = (self->leftflag3_1+1);
      v_68 = (leftforwardDetection==false);
      v_67 = (leftbackwardDetection==false);
      v_69 = (v_67||v_68);
      if (v_69) {
        leftflag3_St_1_ParkingStartTS = v_70;
      } else {
        leftflag3_St_1_ParkingStartTS = self->leftflag3_1;
      };
      dir_St_1_ParkingStartTS = 1;
      flag_St_1_ParkingStartTS = true;
      v_r_St_1_ParkingStartTS = pspeed;
      v_l_St_1_ParkingStartTS = pspeed;
      if (b5) {
        v_60 = true;
      } else {
        v_60 = false;
      };
      if (b4) {
        v_62 = true;
      } else {
        v_62 = v_60;
      };
      if (b5) {
        v_59 = Line_follower__St_1_ParkingDriftLeftTS;
      } else {
        v_59 = Line_follower__St_1_ParkingStartTS;
      };
      if (b4) {
        v_61 = Line_follower__St_1_ParkingDriftRightTS;
      } else {
        v_61 = v_59;
      };
      _out->dir = dir_St_1_ParkingStartTS;
      flag = flag_St_1_ParkingStartTS;
      leftflag1 = leftflag1_St_1_ParkingStartTS;
      rightflag1 = rightflag1_St_1_ParkingStartTS;
      leftflag2 = leftflag2_St_1_ParkingStartTS;
      rightflag2 = rightflag2_St_1_ParkingStartTS;
      leftflag3 = leftflag3_St_1_ParkingStartTS;
      v_55 = (leftflag3>0);
      v_49 = (leftflag3==0);
      rightflag3 = rightflag3_St_1_ParkingStartTS;
      v_57 = (rightflag3>0);
      v_52 = (rightflag3==0);
      timer = timer_St_1_ParkingStartTS;
      timer1 = timer1_St_1_ParkingStartTS;
      v_54 = (timer1<=0);
      v_56 = (v_54&&v_55);
      v_58 = (v_56&&v_57);
      if (v_58) {
        v_64 = true;
        v_63 = Line_follower__St_1_ExitState;
      } else {
        v_64 = v_62;
        v_63 = v_61;
      };
      v_51 = (timer1<=0);
      v_53 = (v_51&&v_52);
      if (v_53) {
        v_66 = true;
        v_65 = Line_follower__St_1_ParkrightBackward;
      } else {
        v_66 = v_64;
        v_65 = v_63;
      };
      v_48 = (timer1<=0);
      v_50 = (v_48&&v_49);
      if (v_50) {
        nr_St_1_ParkingStartTS = true;
        ns_St_1_ParkingStartTS = Line_follower__St_1_ParkleftBackward;
      } else {
        nr_St_1_ParkingStartTS = v_66;
        ns_St_1_ParkingStartTS = v_65;
      };
      rightturn_count = rightturn_count_St_1_ParkingStartTS;
      break;
    case Line_follower__St_1_ParkleftBackward:
      rightturn_count_St_1_ParkleftBackward = self->rightturn_count_1;
      timer_St_1_ParkleftBackward = self->timer_1;
      rightflag3_St_1_ParkleftBackward = self->rightflag3_1;
      leftflag3_St_1_ParkleftBackward = self->leftflag3_1;
      rightflag2_St_1_ParkleftBackward = self->rightflag2_1;
      leftflag2_St_1_ParkleftBackward = self->leftflag2_1;
      rightflag1_St_1_ParkleftBackward = self->rightflag1_1;
      leftflag1_St_1_ParkleftBackward = self->leftflag1_1;
      v_47 = (self->v_46-1);
      if (r) {
        timer1_St_1_ParkleftBackward = 220;
      } else {
        timer1_St_1_ParkleftBackward = v_47;
      };
      flag_St_1_ParkleftBackward = true;
      v_r_St_1_ParkleftBackward = (pspeed-10);
      v_l_St_1_ParkleftBackward = (pspeed-10);
      dir_St_1_ParkleftBackward = 6;
      _out->dir = dir_St_1_ParkleftBackward;
      flag = flag_St_1_ParkleftBackward;
      leftflag1 = leftflag1_St_1_ParkleftBackward;
      rightflag1 = rightflag1_St_1_ParkleftBackward;
      leftflag2 = leftflag2_St_1_ParkleftBackward;
      rightflag2 = rightflag2_St_1_ParkleftBackward;
      leftflag3 = leftflag3_St_1_ParkleftBackward;
      rightflag3 = rightflag3_St_1_ParkleftBackward;
      timer = timer_St_1_ParkleftBackward;
      timer1 = timer1_St_1_ParkleftBackward;
      v_45 = (timer1<=0);
      if (v_45) {
        nr_St_1_ParkleftBackward = true;
        ns_St_1_ParkleftBackward = Line_follower__St_1_LeftTurn_Park;
      } else {
        nr_St_1_ParkleftBackward = false;
        ns_St_1_ParkleftBackward = Line_follower__St_1_ParkleftBackward;
      };
      rightturn_count = rightturn_count_St_1_ParkleftBackward;
      break;
    case Line_follower__St_1_ParkrightBackward:
      rightturn_count_St_1_ParkrightBackward = self->rightturn_count_1;
      timer_St_1_ParkrightBackward = self->timer_1;
      rightflag3_St_1_ParkrightBackward = self->rightflag3_1;
      leftflag3_St_1_ParkrightBackward = self->leftflag3_1;
      rightflag2_St_1_ParkrightBackward = self->rightflag2_1;
      leftflag2_St_1_ParkrightBackward = self->leftflag2_1;
      rightflag1_St_1_ParkrightBackward = self->rightflag1_1;
      leftflag1_St_1_ParkrightBackward = self->leftflag1_1;
      v_44 = (self->v_43-1);
      if (r) {
        timer1_St_1_ParkrightBackward = 220;
      } else {
        timer1_St_1_ParkrightBackward = v_44;
      };
      flag_St_1_ParkrightBackward = true;
      v_r_St_1_ParkrightBackward = (pspeed-10);
      v_l_St_1_ParkrightBackward = (pspeed-10);
      dir_St_1_ParkrightBackward = 6;
      _out->dir = dir_St_1_ParkrightBackward;
      flag = flag_St_1_ParkrightBackward;
      leftflag1 = leftflag1_St_1_ParkrightBackward;
      rightflag1 = rightflag1_St_1_ParkrightBackward;
      leftflag2 = leftflag2_St_1_ParkrightBackward;
      rightflag2 = rightflag2_St_1_ParkrightBackward;
      leftflag3 = leftflag3_St_1_ParkrightBackward;
      rightflag3 = rightflag3_St_1_ParkrightBackward;
      timer = timer_St_1_ParkrightBackward;
      timer1 = timer1_St_1_ParkrightBackward;
      v_42 = (timer1<=0);
      if (v_42) {
        nr_St_1_ParkrightBackward = true;
        ns_St_1_ParkrightBackward = Line_follower__St_1_RightTurn_Park;
      } else {
        nr_St_1_ParkrightBackward = false;
        ns_St_1_ParkrightBackward = Line_follower__St_1_ParkrightBackward;
      };
      rightturn_count = rightturn_count_St_1_ParkrightBackward;
      break;
    case Line_follower__St_1_RightTurn_Park:
      rightturn_count_St_1_RightTurn_Park = self->rightturn_count_1;
      timer1_St_1_RightTurn_Park = self->timer1_1;
      rightflag3_St_1_RightTurn_Park = self->rightflag3_1;
      leftflag3_St_1_RightTurn_Park = self->leftflag3_1;
      rightflag2_St_1_RightTurn_Park = self->rightflag2_1;
      leftflag2_St_1_RightTurn_Park = self->leftflag2_1;
      rightflag1_St_1_RightTurn_Park = self->rightflag1_1;
      leftflag1_St_1_RightTurn_Park = self->leftflag1_1;
      v_41 = (self->v_40-1);
      if (r) {
        timer_St_1_RightTurn_Park = 70;
      } else {
        timer_St_1_RightTurn_Park = v_41;
      };
      flag_St_1_RightTurn_Park = true;
      v_r_St_1_RightTurn_Park = pspeed;
      v_l_St_1_RightTurn_Park = pspeed;
      dir_St_1_RightTurn_Park = 5;
      _out->dir = dir_St_1_RightTurn_Park;
      flag = flag_St_1_RightTurn_Park;
      leftflag1 = leftflag1_St_1_RightTurn_Park;
      rightflag1 = rightflag1_St_1_RightTurn_Park;
      leftflag2 = leftflag2_St_1_RightTurn_Park;
      rightflag2 = rightflag2_St_1_RightTurn_Park;
      leftflag3 = leftflag3_St_1_RightTurn_Park;
      rightflag3 = rightflag3_St_1_RightTurn_Park;
      timer = timer_St_1_RightTurn_Park;
      v_39 = (timer<=0);
      if (v_39) {
        nr_St_1_RightTurn_Park = true;
        ns_St_1_RightTurn_Park = Line_follower__St_1_Forward_1;
      } else {
        nr_St_1_RightTurn_Park = false;
        ns_St_1_RightTurn_Park = Line_follower__St_1_RightTurn_Park;
      };
      timer1 = timer1_St_1_RightTurn_Park;
      rightturn_count = rightturn_count_St_1_RightTurn_Park;
      break;
    case Line_follower__St_1_LeftTurn_Park:
      rightturn_count_St_1_LeftTurn_Park = self->rightturn_count_1;
      timer1_St_1_LeftTurn_Park = self->timer1_1;
      rightflag3_St_1_LeftTurn_Park = self->rightflag3_1;
      leftflag3_St_1_LeftTurn_Park = self->leftflag3_1;
      rightflag2_St_1_LeftTurn_Park = self->rightflag2_1;
      leftflag2_St_1_LeftTurn_Park = self->leftflag2_1;
      rightflag1_St_1_LeftTurn_Park = self->rightflag1_1;
      leftflag1_St_1_LeftTurn_Park = self->leftflag1_1;
      v_38 = (self->v_37-1);
      if (r) {
        timer_St_1_LeftTurn_Park = 40;
      } else {
        timer_St_1_LeftTurn_Park = v_38;
      };
      flag_St_1_LeftTurn_Park = true;
      v_r_St_1_LeftTurn_Park = pspeed;
      v_l_St_1_LeftTurn_Park = pspeed;
      dir_St_1_LeftTurn_Park = 4;
      _out->dir = dir_St_1_LeftTurn_Park;
      flag = flag_St_1_LeftTurn_Park;
      leftflag1 = leftflag1_St_1_LeftTurn_Park;
      rightflag1 = rightflag1_St_1_LeftTurn_Park;
      leftflag2 = leftflag2_St_1_LeftTurn_Park;
      rightflag2 = rightflag2_St_1_LeftTurn_Park;
      leftflag3 = leftflag3_St_1_LeftTurn_Park;
      rightflag3 = rightflag3_St_1_LeftTurn_Park;
      timer = timer_St_1_LeftTurn_Park;
      v_36 = (timer<=0);
      if (v_36) {
        nr_St_1_LeftTurn_Park = true;
        ns_St_1_LeftTurn_Park = Line_follower__St_1_Forward_1;
      } else {
        nr_St_1_LeftTurn_Park = false;
        ns_St_1_LeftTurn_Park = Line_follower__St_1_LeftTurn_Park;
      };
      timer1 = timer1_St_1_LeftTurn_Park;
      rightturn_count = rightturn_count_St_1_LeftTurn_Park;
      break;
    case Line_follower__St_1_Forward_1:
      rightturn_count_St_1_Forward_1 = self->rightturn_count_1;
      timer1_St_1_Forward_1 = self->timer1_1;
      rightflag3_St_1_Forward_1 = self->rightflag3_1;
      leftflag3_St_1_Forward_1 = self->leftflag3_1;
      rightflag2_St_1_Forward_1 = self->rightflag2_1;
      leftflag2_St_1_Forward_1 = self->leftflag2_1;
      rightflag1_St_1_Forward_1 = self->rightflag1_1;
      leftflag1_St_1_Forward_1 = self->leftflag1_1;
      v_35 = (self->v_34-1);
      if (r) {
        timer_St_1_Forward_1 = 200;
      } else {
        timer_St_1_Forward_1 = v_35;
      };
      flag_St_1_Forward_1 = true;
      v_r_St_1_Forward_1 = pspeed;
      v_l_St_1_Forward_1 = pspeed;
      dir_St_1_Forward_1 = 1;
      _out->dir = dir_St_1_Forward_1;
      flag = flag_St_1_Forward_1;
      leftflag1 = leftflag1_St_1_Forward_1;
      rightflag1 = rightflag1_St_1_Forward_1;
      leftflag2 = leftflag2_St_1_Forward_1;
      rightflag2 = rightflag2_St_1_Forward_1;
      leftflag3 = leftflag3_St_1_Forward_1;
      rightflag3 = rightflag3_St_1_Forward_1;
      timer = timer_St_1_Forward_1;
      v_33 = (timer<=0);
      if (v_33) {
        nr_St_1_Forward_1 = true;
        ns_St_1_Forward_1 = Line_follower__St_1_ExitState;
      } else {
        nr_St_1_Forward_1 = false;
        ns_St_1_Forward_1 = Line_follower__St_1_Forward_1;
      };
      timer1 = timer1_St_1_Forward_1;
      rightturn_count = rightturn_count_St_1_Forward_1;
      break;
    case Line_follower__St_1_ExitState:
      rightturn_count_St_1_ExitState = self->rightturn_count_1;
      timer1_St_1_ExitState = self->timer1_1;
      timer_St_1_ExitState = self->timer_1;
      rightflag3_St_1_ExitState = self->rightflag3_1;
      leftflag3_St_1_ExitState = self->leftflag3_1;
      rightflag2_St_1_ExitState = self->rightflag2_1;
      leftflag2_St_1_ExitState = self->leftflag2_1;
      rightflag1_St_1_ExitState = self->rightflag1_1;
      leftflag1_St_1_ExitState = self->leftflag1_1;
      v_r_St_1_ExitState = 0;
      v_l_St_1_ExitState = 0;
      flag_St_1_ExitState = false;
      dir_St_1_ExitState = 0;
      if (true) {
        nr_St_1_ExitState = true;
      } else {
        nr_St_1_ExitState = false;
      };
      if (true) {
        ns_St_1_ExitState = Line_follower__St_1_ExitState;
      } else {
        ns_St_1_ExitState = Line_follower__St_1_ExitState;
      };
      _out->dir = dir_St_1_ExitState;
      flag = flag_St_1_ExitState;
      leftflag1 = leftflag1_St_1_ExitState;
      rightflag1 = rightflag1_St_1_ExitState;
      leftflag2 = leftflag2_St_1_ExitState;
      rightflag2 = rightflag2_St_1_ExitState;
      leftflag3 = leftflag3_St_1_ExitState;
      rightflag3 = rightflag3_St_1_ExitState;
      timer = timer_St_1_ExitState;
      timer1 = timer1_St_1_ExitState;
      rightturn_count = rightturn_count_St_1_ExitState;
      break;
    default:
      break;
  };
  Line_follower__counter_step(sen0, sen1, sen2, sen3, sen4, beacon, flag,
                              &Line_follower__counter_out_st, &self->counter);
  count = Line_follower__counter_out_st.finalcount;
  v_32 = (count>1);
  if (v_32) {
    bspeed = 50;
  } else {
    bspeed = 30;
  };
  _out->cnt = count;
  switch (self->ck) {
    case Line_follower__St_1_BlackForward:
      v_r_St_1_BlackForward = bspeed;
      v_l_St_1_BlackForward = bspeed;
      v_234 = (count>=8);
      v_235 = (blacknodedetected&&v_234);
      if (v_235) {
        v_243 = true;
        v_242 = Line_follower__St_1_ParkingDelay;
      } else {
        v_243 = v_241;
        v_242 = v_240;
      };
      v_231 = (count<8);
      v_230 = (count>4);
      v_232 = (v_230&&v_231);
      v_233 = (blacknodedetected&&v_232);
      if (v_233) {
        v_245 = true;
        v_244 = Line_follower__St_1_BlackLeft;
      } else {
        v_245 = v_243;
        v_244 = v_242;
      };
      v_228 = (count<=4);
      v_229 = (blacknodedetected&&v_228);
      if (v_229) {
        v_247 = true;
      } else {
        v_247 = v_245;
      };
      if (v_227) {
        nr_St_1_BlackForward = true;
      } else {
        nr_St_1_BlackForward = v_247;
      };
      if (v_229) {
        v_246 = Line_follower__St_1_BlackRight;
      } else {
        v_246 = v_244;
      };
      if (v_227) {
        ns_St_1_BlackForward = Line_follower__St_1_ObstacleAvoidance;
      } else {
        ns_St_1_BlackForward = v_246;
      };
      _out->v_l = v_l_St_1_BlackForward;
      _out->v_r = v_r_St_1_BlackForward;
      ns = ns_St_1_BlackForward;
      nr = nr_St_1_BlackForward;
      break;
    case Line_follower__St_1_BlackLeft:
      v_r_St_1_BlackLeft = bspeed;
      v_l_St_1_BlackLeft = bspeed;
      _out->v_l = v_l_St_1_BlackLeft;
      _out->v_r = v_r_St_1_BlackLeft;
      ns = ns_St_1_BlackLeft;
      nr = nr_St_1_BlackLeft;
      break;
    case Line_follower__St_1_BlackRight:
      v_r_St_1_BlackRight = bspeed;
      v_l_St_1_BlackRight = bspeed;
      _out->v_l = v_l_St_1_BlackRight;
      _out->v_r = v_r_St_1_BlackRight;
      ns = ns_St_1_BlackRight;
      nr = nr_St_1_BlackRight;
      break;
    case Line_follower__St_1_BlackDriftLeft:
      v_r_St_1_BlackDriftLeft = (bspeed+pid);
      _out->v_l = v_l_St_1_BlackDriftLeft;
      _out->v_r = v_r_St_1_BlackDriftLeft;
      ns = ns_St_1_BlackDriftLeft;
      nr = nr_St_1_BlackDriftLeft;
      break;
    case Line_follower__St_1_BlackDriftRight:
      v_l_St_1_BlackDriftRight = (bspeed+pid);
      _out->v_l = v_l_St_1_BlackDriftRight;
      _out->v_r = v_r_St_1_BlackDriftRight;
      ns = ns_St_1_BlackDriftRight;
      nr = nr_St_1_BlackDriftRight;
      break;
    case Line_follower__St_1_ExitState:
      _out->v_l = v_l_St_1_ExitState;
      _out->v_r = v_r_St_1_ExitState;
      ns = ns_St_1_ExitState;
      nr = nr_St_1_ExitState;
      break;
    case Line_follower__St_1_Forward_1:
      _out->v_l = v_l_St_1_Forward_1;
      _out->v_r = v_r_St_1_Forward_1;
      ns = ns_St_1_Forward_1;
      nr = nr_St_1_Forward_1;
      self->v_34 = timer;
      break;
    case Line_follower__St_1_LeftTurn_Park:
      _out->v_l = v_l_St_1_LeftTurn_Park;
      _out->v_r = v_r_St_1_LeftTurn_Park;
      ns = ns_St_1_LeftTurn_Park;
      nr = nr_St_1_LeftTurn_Park;
      self->v_37 = timer;
      break;
    case Line_follower__St_1_RightTurn_Park:
      _out->v_l = v_l_St_1_RightTurn_Park;
      _out->v_r = v_r_St_1_RightTurn_Park;
      ns = ns_St_1_RightTurn_Park;
      nr = nr_St_1_RightTurn_Park;
      self->v_40 = timer;
      break;
    case Line_follower__St_1_ParkrightBackward:
      _out->v_l = v_l_St_1_ParkrightBackward;
      _out->v_r = v_r_St_1_ParkrightBackward;
      ns = ns_St_1_ParkrightBackward;
      nr = nr_St_1_ParkrightBackward;
      self->v_43 = timer1;
      break;
    case Line_follower__St_1_ParkleftBackward:
      _out->v_l = v_l_St_1_ParkleftBackward;
      _out->v_r = v_r_St_1_ParkleftBackward;
      ns = ns_St_1_ParkleftBackward;
      nr = nr_St_1_ParkleftBackward;
      self->v_46 = timer1;
      break;
    case Line_follower__St_1_ParkingStartTS:
      _out->v_l = v_l_St_1_ParkingStartTS;
      _out->v_r = v_r_St_1_ParkingStartTS;
      ns = ns_St_1_ParkingStartTS;
      nr = nr_St_1_ParkingStartTS;
      self->v_75 = timer1;
      break;
    case Line_follower__St_1_DelayP2:
      _out->v_l = v_l_St_1_DelayP2;
      _out->v_r = v_r_St_1_DelayP2;
      ns = ns_St_1_DelayP2;
      nr = nr_St_1_DelayP2;
      self->v_78 = timer1;
      break;
    case Line_follower__St_1_ParkingStartSS:
      _out->v_l = v_l_St_1_ParkingStartSS;
      _out->v_r = v_r_St_1_ParkingStartSS;
      ns = ns_St_1_ParkingStartSS;
      nr = nr_St_1_ParkingStartSS;
      self->v_107 = timer1;
      break;
    case Line_follower__St_1_DelayP1:
      _out->v_l = v_l_St_1_DelayP1;
      _out->v_r = v_r_St_1_DelayP1;
      ns = ns_St_1_DelayP1;
      nr = nr_St_1_DelayP1;
      self->v_110 = timer1;
      break;
    case Line_follower__St_1_ParkingStartFS:
      _out->v_l = v_l_St_1_ParkingStartFS;
      _out->v_r = v_r_St_1_ParkingStartFS;
      ns = ns_St_1_ParkingStartFS;
      nr = nr_St_1_ParkingStartFS;
      self->v_139 = timer1;
      break;
    case Line_follower__St_1_PreParkingDriftRight:
      _out->v_l = v_l_St_1_PreParkingDriftRight;
      _out->v_r = v_r_St_1_PreParkingDriftRight;
      ns = ns_St_1_PreParkingDriftRight;
      nr = nr_St_1_PreParkingDriftRight;
      break;
    case Line_follower__St_1_PreParkingDriftLeft:
      _out->v_l = v_l_St_1_PreParkingDriftLeft;
      _out->v_r = v_r_St_1_PreParkingDriftLeft;
      ns = ns_St_1_PreParkingDriftLeft;
      nr = nr_St_1_PreParkingDriftLeft;
      break;
    case Line_follower__St_1_Forwardoneparking:
      _out->v_l = v_l_St_1_Forwardoneparking;
      _out->v_r = v_r_St_1_Forwardoneparking;
      ns = ns_St_1_Forwardoneparking;
      nr = nr_St_1_Forwardoneparking;
      break;
    case Line_follower__St_1_FirstleftParking:
      _out->v_l = v_l_St_1_FirstleftParking;
      _out->v_r = v_r_St_1_FirstleftParking;
      ns = ns_St_1_FirstleftParking;
      nr = nr_St_1_FirstleftParking;
      break;
    case Line_follower__St_1_Parking:
      _out->v_l = v_l_St_1_Parking;
      _out->v_r = v_r_St_1_Parking;
      ns = ns_St_1_Parking;
      nr = nr_St_1_Parking;
      break;
    case Line_follower__St_1_ParkingDelay:
      _out->v_l = v_l_St_1_ParkingDelay;
      _out->v_r = v_r_St_1_ParkingDelay;
      ns = ns_St_1_ParkingDelay;
      nr = nr_St_1_ParkingDelay;
      self->v_157 = timer;
      break;
    case Line_follower__St_1_ParkingDriftRightTS:
      _out->v_l = v_l_St_1_ParkingDriftRightTS;
      _out->v_r = v_r_St_1_ParkingDriftRightTS;
      ns = ns_St_1_ParkingDriftRightTS;
      nr = nr_St_1_ParkingDriftRightTS;
      break;
    case Line_follower__St_1_ParkingDriftLeftTS:
      _out->v_l = v_l_St_1_ParkingDriftLeftTS;
      _out->v_r = v_r_St_1_ParkingDriftLeftTS;
      ns = ns_St_1_ParkingDriftLeftTS;
      nr = nr_St_1_ParkingDriftLeftTS;
      break;
    case Line_follower__St_1_ParkingDriftRightSS:
      _out->v_l = v_l_St_1_ParkingDriftRightSS;
      _out->v_r = v_r_St_1_ParkingDriftRightSS;
      ns = ns_St_1_ParkingDriftRightSS;
      nr = nr_St_1_ParkingDriftRightSS;
      break;
    case Line_follower__St_1_ParkingDriftLeftSS:
      _out->v_l = v_l_St_1_ParkingDriftLeftSS;
      _out->v_r = v_r_St_1_ParkingDriftLeftSS;
      ns = ns_St_1_ParkingDriftLeftSS;
      nr = nr_St_1_ParkingDriftLeftSS;
      break;
    case Line_follower__St_1_ParkingDriftRight:
      _out->v_l = v_l_St_1_ParkingDriftRight;
      _out->v_r = v_r_St_1_ParkingDriftRight;
      ns = ns_St_1_ParkingDriftRight;
      nr = nr_St_1_ParkingDriftRight;
      break;
    case Line_follower__St_1_ParkingDriftLeft:
      _out->v_l = v_l_St_1_ParkingDriftLeft;
      _out->v_r = v_r_St_1_ParkingDriftLeft;
      ns = ns_St_1_ParkingDriftLeft;
      nr = nr_St_1_ParkingDriftLeft;
      break;
    case Line_follower__St_1_RightTurn3:
      _out->v_l = v_l_St_1_RightTurn3;
      _out->v_r = v_r_St_1_RightTurn3;
      ns = ns_St_1_RightTurn3;
      nr = nr_St_1_RightTurn3;
      self->v_184 = timer;
      break;
    case Line_follower__St_1_Move5:
      _out->v_l = v_l_St_1_Move5;
      _out->v_r = v_r_St_1_Move5;
      ns = ns_St_1_Move5;
      nr = nr_St_1_Move5;
      break;
    case Line_follower__St_1_LeftTurn2:
      _out->v_l = v_l_St_1_LeftTurn2;
      _out->v_r = v_r_St_1_LeftTurn2;
      ns = ns_St_1_LeftTurn2;
      nr = nr_St_1_LeftTurn2;
      self->v_188 = timer;
      break;
    case Line_follower__St_1_Forward2:
      _out->v_l = v_l_St_1_Forward2;
      _out->v_r = v_r_St_1_Forward2;
      ns = ns_St_1_Forward2;
      nr = nr_St_1_Forward2;
      break;
    case Line_follower__St_1_Move3:
      _out->v_l = v_l_St_1_Move3;
      _out->v_r = v_r_St_1_Move3;
      ns = ns_St_1_Move3;
      nr = nr_St_1_Move3;
      break;
    case Line_follower__St_1_LeftTurn1:
      _out->v_l = v_l_St_1_LeftTurn1;
      _out->v_r = v_r_St_1_LeftTurn1;
      ns = ns_St_1_LeftTurn1;
      nr = nr_St_1_LeftTurn1;
      self->v_193 = timer;
      break;
    case Line_follower__St_1_Forward1:
      _out->v_l = v_l_St_1_Forward1;
      _out->v_r = v_r_St_1_Forward1;
      ns = ns_St_1_Forward1;
      nr = nr_St_1_Forward1;
      self->v_198 = rightturn_count;
      break;
    case Line_follower__St_1_Move1:
      _out->v_l = v_l_St_1_Move1;
      _out->v_r = v_r_St_1_Move1;
      ns = ns_St_1_Move1;
      nr = nr_St_1_Move1;
      break;
    case Line_follower__St_1_RightTurn1:
      _out->v_l = v_l_St_1_RightTurn1;
      _out->v_r = v_r_St_1_RightTurn1;
      ns = ns_St_1_RightTurn1;
      nr = nr_St_1_RightTurn1;
      self->v_202 = timer;
      break;
    case Line_follower__St_1_ObstacleAvoidance:
      _out->v_l = v_l_St_1_ObstacleAvoidance;
      _out->v_r = v_r_St_1_ObstacleAvoidance;
      ns = ns_St_1_ObstacleAvoidance;
      nr = nr_St_1_ObstacleAvoidance;
      self->v_205 = timer;
      break;
    case Line_follower__St_1_DriftRight:
      _out->v_l = v_l_St_1_DriftRight;
      _out->v_r = v_r_St_1_DriftRight;
      ns = ns_St_1_DriftRight;
      nr = nr_St_1_DriftRight;
      break;
    case Line_follower__St_1_DriftLeft:
      _out->v_l = v_l_St_1_DriftLeft;
      _out->v_r = v_r_St_1_DriftLeft;
      ns = ns_St_1_DriftLeft;
      nr = nr_St_1_DriftLeft;
      break;
    case Line_follower__St_1_Right:
      _out->v_l = v_l_St_1_Right;
      _out->v_r = v_r_St_1_Right;
      ns = ns_St_1_Right;
      nr = nr_St_1_Right;
      break;
    case Line_follower__St_1_Left:
      _out->v_l = v_l_St_1_Left;
      _out->v_r = v_r_St_1_Left;
      ns = ns_St_1_Left;
      nr = nr_St_1_Left;
      break;
    case Line_follower__St_1_Stop:
      _out->v_l = v_l_St_1_Stop;
      _out->v_r = v_r_St_1_Stop;
      ns = ns_St_1_Stop;
      nr = nr_St_1_Stop;
      break;
    case Line_follower__St_1_Forward:
      _out->v_l = v_l_St_1_Forward;
      _out->v_r = v_r_St_1_Forward;
      ns = ns_St_1_Forward;
      nr = nr_St_1_Forward;
      break;
    default:
      break;
  };
  self->rightturn_count_1 = rightturn_count;
  self->timer1_1 = timer1;
  self->timer_1 = timer;
  self->rightflag3_1 = rightflag3;
  self->leftflag3_1 = leftflag3;
  self->rightflag2_1 = rightflag2;
  self->leftflag2_1 = leftflag2;
  self->rightflag1_1 = rightflag1;
  self->leftflag1_1 = leftflag1;
  self->cnt_1 = _out->cnt;
  self->pnr = nr;
  self->ck = ns;;
}

