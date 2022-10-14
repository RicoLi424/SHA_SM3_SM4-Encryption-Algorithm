/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */
extern signed int intermediateHash[8];
extern signed int messageBlock[16];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int LeftRotate(signed int llvm_cbe_X,  char llvm_cbe_i);
signed int T( char llvm_cbe_i);
signed int FF(signed int llvm_cbe_X, signed int llvm_cbe_Y, signed int llvm_cbe_Z,  char llvm_cbe_i);
signed int GG(signed int llvm_cbe_X, signed int llvm_cbe_Y, signed int llvm_cbe_Z,  char llvm_cbe_i);
signed int P0(signed int llvm_cbe_X);
signed int P1(signed int llvm_cbe_X);
void initial(signed int *llvm_cbe_X);
void processmessageblock(signed int *llvm_cbe_intermediateHash, signed int *llvm_cbe_messageBlock);
void SM3Calc( char *llvm_cbe_message,  char llvm_cbe_messageLen, signed int *llvm_cbe_digest);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str2[40] = "D:/vivado/sm3/hls_prj/SM3/SM3/src/SM3.c";
static  char aesl_internal__OC_str5[155] = "(i * 32 + 31 >= 0 && i * 32 + 31 < (__bitwidthof__(typeof(pack))) && i * 32 < (__bitwidthof__(typeof(pack))) && i * 32 >= 0) && \"Part select out of range\"";
static  char aesl_internal__OC_str6[6] = "%08x\n";
signed int intermediateHash[8] __ATTRIBUTE_WEAK__;
signed int messageBlock[16] __ATTRIBUTE_WEAK__;


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int LeftRotate(signed int llvm_cbe_X,  char llvm_cbe_i) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned int llvm_cbe_tmp__12;
  unsigned int llvm_cbe_tmp__12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @LeftRotate\n");
  if ((((unsigned char )llvm_cbe_i&63U) < ((unsigned char )((unsigned char )-31)&63U))) {
    goto llvm_cbe_tmp__13;
  } else {
    goto llvm_cbe_tmp__14;
  }

llvm_cbe_tmp__13:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i6 %%i to i32, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_i&63U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl i32 %%X, %%3, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__2 = (unsigned int )llvm_cbe_X << llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sub nsw i32 32, %%3, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(32u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = lshr i32 %%X, %%5, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_X&4294967295ull)) >> ((unsigned int )(llvm_cbe_tmp__3&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = or i32 %%6, %%4, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__5 = (unsigned int )llvm_cbe_tmp__4 | llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
  llvm_cbe_tmp__12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__5;   /* for PHI node */
  goto llvm_cbe_tmp__15;

llvm_cbe_tmp__14:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i6 %%i to i32, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_i&63U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, -32, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_tmp__6&4294967295ull)) + ((unsigned int )(4294967264u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i32 %%X, %%10, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__8 = (unsigned int )llvm_cbe_X << llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub nsw i32 64, %%9, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(64u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__6&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = lshr i32 %%X, %%12, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_X&4294967295ull)) >> ((unsigned int )(llvm_cbe_tmp__9&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = or i32 %%11, %%13, !dbg !10 for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__11 = (unsigned int )llvm_cbe_tmp__8 | llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
  llvm_cbe_tmp__12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__11;   /* for PHI node */
  goto llvm_cbe_tmp__15;

llvm_cbe_tmp__15:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = phi i32 [ %%14, %%8 ], [ %%7, %%2  for 0x%I64xth hint within @LeftRotate  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__12 = (unsigned int )llvm_cbe_tmp__12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__12);
printf("\n = 0x%X",llvm_cbe_tmp__11);
printf("\n = 0x%X",llvm_cbe_tmp__5);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @LeftRotate}\n");
  return llvm_cbe_tmp__12;
}


signed int T( char llvm_cbe_i) {
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @T\n");
  if ((((unsigned char )llvm_cbe_i&127U) < ((unsigned char )((unsigned char )16)&127U))) {
    goto llvm_cbe_tmp__16;
  } else {
    goto llvm_cbe_tmp__17;
  }

llvm_cbe_tmp__17:
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%3, i32 2055708042, i32 0, !dbg !10 for 0x%I64xth hint within @T  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((( char )(llvm_cbe_i & (1U << 6U )  ? llvm_cbe_i | 4294967168U : llvm_cbe_i & 127U)) > (( char )(((unsigned char )-1) & (1U << 6U )  ? ((unsigned char )-1) | 4294967168U : ((unsigned char )-1) & 127U)))) ? ((unsigned int )2055708042u) : ((unsigned int )0u));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @T}\n");
  return llvm_cbe__2e_;
llvm_cbe_tmp__16:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @T}\n");
  return 2043430169u;
}


signed int FF(signed int llvm_cbe_X, signed int llvm_cbe_Y, signed int llvm_cbe_Z,  char llvm_cbe_i) {
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned int llvm_cbe_tmp__24;
  unsigned int llvm_cbe_tmp__24__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @FF\n");
  if ((((unsigned char )llvm_cbe_i&127U) < ((unsigned char )((unsigned char )16)&127U))) {
    goto llvm_cbe_tmp__25;
  } else {
    goto llvm_cbe_tmp__26;
  }

llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = xor i32 %%Y, %%X, !dbg !10 for 0x%I64xth hint within @FF  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__18 = (unsigned int )llvm_cbe_Y ^ llvm_cbe_X;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = xor i32 %%3, %%Z, !dbg !10 for 0x%I64xth hint within @FF  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__19 = (unsigned int )llvm_cbe_tmp__18 ^ llvm_cbe_Z;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
  llvm_cbe_tmp__24__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__19;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__26:
  if (((( char )(llvm_cbe_i & (1U << 6U )  ? llvm_cbe_i | 4294967168U : llvm_cbe_i & 127U)) > (( char )(((unsigned char )-1) & (1U << 6U )  ? ((unsigned char )-1) | 4294967168U : ((unsigned char )-1) & 127U)))) {
    goto llvm_cbe_tmp__28;
  } else {
    llvm_cbe_tmp__24__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__27;
  }

llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = or i32 %%Z, %%Y, !dbg !10 for 0x%I64xth hint within @FF  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__20 = (unsigned int )llvm_cbe_Z | llvm_cbe_Y;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = and i32 %%8, %%X, !dbg !10 for 0x%I64xth hint within @FF  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__21 = (unsigned int )llvm_cbe_tmp__20 & llvm_cbe_X;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = and i32 %%Z, %%Y, !dbg !10 for 0x%I64xth hint within @FF  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__22 = (unsigned int )llvm_cbe_Z & llvm_cbe_Y;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = or i32 %%9, %%10, !dbg !10 for 0x%I64xth hint within @FF  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__23 = (unsigned int )llvm_cbe_tmp__21 | llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
  llvm_cbe_tmp__24__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__23;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__27:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i32 [ %%11, %%7 ], [ %%4, %%2 ], [ 0, %%5  for 0x%I64xth hint within @FF  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__24 = (unsigned int )llvm_cbe_tmp__24__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__24);
printf("\n = 0x%X",llvm_cbe_tmp__23);
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @FF}\n");
  return llvm_cbe_tmp__24;
}


signed int GG(signed int llvm_cbe_X, signed int llvm_cbe_Y, signed int llvm_cbe_Z,  char llvm_cbe_i) {
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned int llvm_cbe_tmp__35;
  unsigned int llvm_cbe_tmp__35__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @GG\n");
  if ((((unsigned char )llvm_cbe_i&127U) < ((unsigned char )((unsigned char )16)&127U))) {
    goto llvm_cbe_tmp__36;
  } else {
    goto llvm_cbe_tmp__37;
  }

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = xor i32 %%Y, %%X, !dbg !10 for 0x%I64xth hint within @GG  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__29 = (unsigned int )llvm_cbe_Y ^ llvm_cbe_X;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = xor i32 %%3, %%Z, !dbg !10 for 0x%I64xth hint within @GG  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__30 = (unsigned int )llvm_cbe_tmp__29 ^ llvm_cbe_Z;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
  llvm_cbe_tmp__35__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__30;   /* for PHI node */
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__37:
  if (((( char )(llvm_cbe_i & (1U << 6U )  ? llvm_cbe_i | 4294967168U : llvm_cbe_i & 127U)) > (( char )(((unsigned char )-1) & (1U << 6U )  ? ((unsigned char )-1) | 4294967168U : ((unsigned char )-1) & 127U)))) {
    goto llvm_cbe_tmp__39;
  } else {
    llvm_cbe_tmp__35__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__38;
  }

llvm_cbe_tmp__39:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = and i32 %%Y, %%X, !dbg !10 for 0x%I64xth hint within @GG  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__31 = (unsigned int )llvm_cbe_Y & llvm_cbe_X;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = xor i32 %%X, -1, !dbg !10 for 0x%I64xth hint within @GG  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__32 = (unsigned int )llvm_cbe_X ^ 4294967295u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = and i32 %%Z, %%9, !dbg !10 for 0x%I64xth hint within @GG  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__33 = (unsigned int )llvm_cbe_Z & llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = or i32 %%10, %%8, !dbg !10 for 0x%I64xth hint within @GG  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__34 = (unsigned int )llvm_cbe_tmp__33 | llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
  llvm_cbe_tmp__35__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__34;   /* for PHI node */
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__38:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i32 [ %%11, %%7 ], [ %%4, %%2 ], [ 0, %%5  for 0x%I64xth hint within @GG  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__35 = (unsigned int )llvm_cbe_tmp__35__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__35);
printf("\n = 0x%X",llvm_cbe_tmp__34);
printf("\n = 0x%X",llvm_cbe_tmp__30);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @GG}\n");
  return llvm_cbe_tmp__35;
}


signed int P0(signed int llvm_cbe_X) {
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @P0\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 @LeftRotate(i32 %%X, i6 zeroext 9), !dbg !10 for 0x%I64xth hint within @P0  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__40 = (unsigned int ) /*tail*/ LeftRotate(llvm_cbe_X, ((unsigned char )9));
if (AESL_DEBUG_TRACE) {
printf("\nArgument X = 0x%X",llvm_cbe_X);
printf("\nArgument  = 0x%X",((unsigned char )9));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 @LeftRotate(i32 %%X, i6 zeroext 17), !dbg !10 for 0x%I64xth hint within @P0  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__41 = (unsigned int ) /*tail*/ LeftRotate(llvm_cbe_X, ((unsigned char )17));
if (AESL_DEBUG_TRACE) {
printf("\nArgument X = 0x%X",llvm_cbe_X);
printf("\nArgument  = 0x%X",((unsigned char )17));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = xor i32 %%1, %%X, !dbg !10 for 0x%I64xth hint within @P0  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__42 = (unsigned int )llvm_cbe_tmp__40 ^ llvm_cbe_X;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = xor i32 %%3, %%2, !dbg !10 for 0x%I64xth hint within @P0  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__43 = (unsigned int )llvm_cbe_tmp__42 ^ llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @P0}\n");
  return llvm_cbe_tmp__43;
}


signed int P1(signed int llvm_cbe_X) {
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @P1\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 @LeftRotate(i32 %%X, i6 zeroext 15), !dbg !10 for 0x%I64xth hint within @P1  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__44 = (unsigned int ) /*tail*/ LeftRotate(llvm_cbe_X, ((unsigned char )15));
if (AESL_DEBUG_TRACE) {
printf("\nArgument X = 0x%X",llvm_cbe_X);
printf("\nArgument  = 0x%X",((unsigned char )15));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__44);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 @LeftRotate(i32 %%X, i6 zeroext 23), !dbg !10 for 0x%I64xth hint within @P1  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__45 = (unsigned int ) /*tail*/ LeftRotate(llvm_cbe_X, ((unsigned char )23));
if (AESL_DEBUG_TRACE) {
printf("\nArgument X = 0x%X",llvm_cbe_X);
printf("\nArgument  = 0x%X",((unsigned char )23));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = xor i32 %%1, %%X, !dbg !10 for 0x%I64xth hint within @P1  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__46 = (unsigned int )llvm_cbe_tmp__44 ^ llvm_cbe_X;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = xor i32 %%3, %%2, !dbg !10 for 0x%I64xth hint within @P1  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__47 = (unsigned int )llvm_cbe_tmp__46 ^ llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @P1}\n");
  return llvm_cbe_tmp__47;
}


void initial(signed int *llvm_cbe_X) {
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  signed int *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  signed int *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  signed int *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  signed int *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  signed int *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  signed int *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  signed int *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @initial\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1937774191, i32* %%X, align 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_129_count);
  *llvm_cbe_X = 1937774191u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1937774191u);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds i32* %%X, i64 1, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__48 = (signed int *)(&llvm_cbe_X[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1226093241, i32* %%1, align 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_131_count);
  *llvm_cbe_tmp__48 = 1226093241u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1226093241u);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i32* %%X, i64 2, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__49 = (signed int *)(&llvm_cbe_X[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 388252375, i32* %%2, align 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_133_count);
  *llvm_cbe_tmp__49 = 388252375u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 388252375u);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i32* %%X, i64 3, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__50 = (signed int *)(&llvm_cbe_X[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 -628488704, i32* %%3, align 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_135_count);
  *llvm_cbe_tmp__50 = 3666478592u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 3666478592u);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i32* %%X, i64 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__51 = (signed int *)(&llvm_cbe_X[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 -1452330820, i32* %%4, align 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_137_count);
  *llvm_cbe_tmp__51 = 2842636476u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 2842636476u);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i32* %%X, i64 5, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__52 = (signed int *)(&llvm_cbe_X[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 372324522, i32* %%5, align 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_139_count);
  *llvm_cbe_tmp__52 = 372324522u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 372324522u);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i32* %%X, i64 6, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__53 = (signed int *)(&llvm_cbe_X[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 -477237683, i32* %%6, align 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_141_count);
  *llvm_cbe_tmp__53 = 3817729613u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 3817729613u);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i32* %%X, i64 7, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__54 = (signed int *)(&llvm_cbe_X[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 -1325724082, i32* %%7, align 4, !dbg !10 for 0x%I64xth hint within @initial  --> \n", ++aesl_llvm_cbe_143_count);
  *llvm_cbe_tmp__54 = 2969243214u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 2969243214u);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @initial}\n");
  return;
}


void processmessageblock(signed int *llvm_cbe_intermediateHash, signed int *llvm_cbe_messageBlock) {
  static  unsigned long long aesl_llvm_cbe_W_count = 0;
  signed int llvm_cbe_W[68];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_W__count = 0;
  signed int llvm_cbe_W_[64];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned char llvm_cbe_storemerge15;
  unsigned char llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  signed int *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  signed int *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  unsigned char llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond25_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge114_count = 0;
  unsigned char llvm_cbe_storemerge114;
  unsigned char llvm_cbe_storemerge114__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  unsigned long long llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  signed int *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  signed int *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  unsigned int llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  signed int *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  unsigned int llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  signed int *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  unsigned int llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  signed int *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  unsigned int llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  signed int *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned char llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond24_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge212_count = 0;
  unsigned char llvm_cbe_storemerge212;
  unsigned char llvm_cbe_storemerge212__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  signed int *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned int llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  signed int *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  signed int *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  unsigned char llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond23_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  unsigned int llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  signed int *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  unsigned int llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  signed int *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  signed int *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned int llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  signed int *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  unsigned int llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  signed int *llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  unsigned int llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  signed int *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned int llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  signed int *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned int llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge311_count = 0;
  unsigned char llvm_cbe_storemerge311;
  unsigned char llvm_cbe_storemerge311__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  unsigned int llvm_cbe_tmp__120;
  unsigned int llvm_cbe_tmp__120__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  unsigned int llvm_cbe_tmp__121;
  unsigned int llvm_cbe_tmp__121__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  unsigned int llvm_cbe_tmp__122;
  unsigned int llvm_cbe_tmp__122__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  unsigned int llvm_cbe_tmp__123;
  unsigned int llvm_cbe_tmp__123__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  unsigned int llvm_cbe_tmp__124;
  unsigned int llvm_cbe_tmp__124__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  unsigned int llvm_cbe_tmp__125;
  unsigned int llvm_cbe_tmp__125__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  unsigned int llvm_cbe_tmp__126;
  unsigned int llvm_cbe_tmp__126__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  unsigned int llvm_cbe_tmp__127;
  unsigned int llvm_cbe_tmp__127__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  unsigned int llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  unsigned int llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  unsigned char llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  unsigned int llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  unsigned int llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  unsigned int llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  unsigned int llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  unsigned int llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  unsigned int llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  unsigned long long llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  signed int *llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  unsigned int llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  unsigned int llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  unsigned int llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  unsigned int llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  unsigned int llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  signed int *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  unsigned int llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  unsigned int llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  unsigned int llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  unsigned int llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  unsigned int llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  unsigned int llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned int llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  unsigned char llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  unsigned int llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  unsigned int llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  unsigned int llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  unsigned int llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  unsigned int llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  unsigned int llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  unsigned int llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  unsigned int llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @processmessageblock\n");
  llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe_tmp__161;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__161:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i7 [ 0, %%0 ], [ %%9, %%1  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned char )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%X",llvm_cbe_storemerge15);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i7 %%storemerge15 to i64, !dbg !12 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__55 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge15&127U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i32* %%messageBlock, i64 %%2, !dbg !12 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__56 = (signed int *)(&llvm_cbe_messageBlock[(((signed long long )llvm_cbe_tmp__55))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__55));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !12 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__57 = (unsigned int )*llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i7 %%storemerge15 to i32, !dbg !12 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__58 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge15&127U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sub nsw i32 15, %%5, !dbg !12 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(15u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__58&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !12 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__60 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%7, !dbg !12 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__61 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__60))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__60));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__60) < 68 && "Write access out of array 'W' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%4, i32* %%8, align 4, !dbg !12 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_200_count);
  *llvm_cbe_tmp__61 = llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i7 %%storemerge15, 1, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__62 = (unsigned char )((unsigned char )(llvm_cbe_storemerge15&127ull)) + ((unsigned char )(((unsigned char )1)&127ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__62&127ull)));
  if (((llvm_cbe_tmp__62&127U) == (((unsigned char )16)&127U))) {
    llvm_cbe_storemerge114__PHI_TEMPORARY = (unsigned char )((unsigned char )16);   /* for PHI node */
    goto llvm_cbe__2e_preheader13;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__62;   /* for PHI node */
    goto llvm_cbe_tmp__161;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader13' to make GCC happy */
llvm_cbe__2e_preheader13:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge114 = phi i7 [ %%40, %%.preheader13 ], [ 16, %%1  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_storemerge114_count);
  llvm_cbe_storemerge114 = (unsigned char )llvm_cbe_storemerge114__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge114 = 0x%X",llvm_cbe_storemerge114);
printf("\n = 0x%X",llvm_cbe_tmp__93);
printf("\n = 0x%X",((unsigned char )16));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i7 %%storemerge114 to i32, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__63 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge114&127U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add nsw i32 %%10, -16, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__64 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) + ((unsigned int )(4294967280u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__64&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%11 to i64, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_231_count);
  llvm_cbe_tmp__65 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%12, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__66 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__65))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__65));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__65) < 68)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%13, align 4, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__67 = (unsigned int )*llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%10, -9, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_234_count);
  llvm_cbe_tmp__68 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) + ((unsigned int )(4294967287u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__68&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__69 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%16, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_236_count);
  llvm_cbe_tmp__70 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__69))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__69) < 68)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__71 = (unsigned int )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%10, -3, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__72 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) + ((unsigned int )(4294967293u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__72&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%19 to i64, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__73 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%20, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__74 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__73))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__73));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__73) < 68)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%21, align 4, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__75 = (unsigned int )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i32 @LeftRotate(i32 %%22, i6 zeroext 15), !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__76 = (unsigned int )LeftRotate(llvm_cbe_tmp__75, ((unsigned char )15));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__75);
printf("\nArgument  = 0x%X",((unsigned char )15));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__76);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = xor i32 %%18, %%14, !dbg !13 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__77 = (unsigned int )llvm_cbe_tmp__71 ^ llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = xor i32 %%24, %%23, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__78 = (unsigned int )llvm_cbe_tmp__77 ^ llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i32 @P1(i32 %%25), !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__79 = (unsigned int )P1(llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__78);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__79);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%10, -13, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__80 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) + ((unsigned int )(4294967283u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__80&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%27 to i64, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__81 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%28, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__82 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__81))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__81));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__81) < 68)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i32* %%29, align 4, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__83 = (unsigned int )*llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = call i32 @LeftRotate(i32 %%30, i6 zeroext 7), !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__84 = (unsigned int )LeftRotate(llvm_cbe_tmp__83, ((unsigned char )7));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__83);
printf("\nArgument  = 0x%X",((unsigned char )7));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__84);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%10, -6, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__85 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) + ((unsigned int )(4294967290u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__85&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%32 to i64, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__86 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%33, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__87 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__86))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__86));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__86) < 68)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i32* %%34, align 4, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__88 = (unsigned int )*llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = xor i32 %%31, %%26, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__89 = (unsigned int )llvm_cbe_tmp__84 ^ llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = xor i32 %%36, %%35, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__90 = (unsigned int )llvm_cbe_tmp__89 ^ llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = zext i7 %%storemerge114 to i64, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_257_count);
  llvm_cbe_tmp__91 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge114&127U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%38, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_258_count);
  llvm_cbe_tmp__92 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__91))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__91));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__91) < 68 && "Write access out of array 'W' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%37, i32* %%39, align 4, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_259_count);
  *llvm_cbe_tmp__92 = llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i7 %%storemerge114, 1, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__93 = (unsigned char )((unsigned char )(llvm_cbe_storemerge114&127ull)) + ((unsigned char )(((unsigned char )1)&127ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__93&127ull)));
  if (((llvm_cbe_tmp__93&127U) == (((unsigned char )-60)&127U))) {
    llvm_cbe_storemerge212__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge114__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__93;   /* for PHI node */
    goto llvm_cbe__2e_preheader13;
  }

  } while (1); /* end of syntactic loop '.preheader13' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge212 = phi i7 [ %%51, %%.preheader ], [ 0, %%.preheader13  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_storemerge212_count);
  llvm_cbe_storemerge212 = (unsigned char )llvm_cbe_storemerge212__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge212 = 0x%X",llvm_cbe_storemerge212);
printf("\n = 0x%X",llvm_cbe_tmp__104);
printf("\n = 0x%X",((unsigned char )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = zext i7 %%storemerge212 to i64, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__94 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge212&127U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%41, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__95 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__94))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__94));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__94) < 68)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i32* %%42, align 4, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__96 = (unsigned int )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = zext i7 %%storemerge212 to i32, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__97 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge212&127U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add nsw i32 %%44, 4, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__98 = (unsigned int )((unsigned int )(llvm_cbe_tmp__97&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__98&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = zext i32 %%45 to i64, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__99 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__98&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%46, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__100 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__99))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__99));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__99) < 68)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i32* %%47, align 4, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__101 = (unsigned int )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = xor i32 %%48, %%43, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_296_count);
  llvm_cbe_tmp__102 = (unsigned int )llvm_cbe_tmp__101 ^ llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds [64 x i32]* %%W_, i64 0, i64 %%41, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_297_count);
  llvm_cbe_tmp__103 = (signed int *)(&llvm_cbe_W_[(((signed long long )llvm_cbe_tmp__94))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__94));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__94) < 64 && "Write access out of array 'W_' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%49, i32* %%50, align 4, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_298_count);
  *llvm_cbe_tmp__103 = llvm_cbe_tmp__102;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add i7 %%storemerge212, 1, !dbg !14 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__104 = (unsigned char )((unsigned char )(llvm_cbe_storemerge212&127ull)) + ((unsigned char )(((unsigned char )1)&127ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__104&127ull)));
  if (((llvm_cbe_tmp__104&127U) == (((unsigned char )64u)&127U))) {
    goto llvm_cbe_tmp__162;
  } else {
    llvm_cbe_storemerge212__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__104;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__162:
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load i32* %%intermediateHash, align 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__105 = (unsigned int )*llvm_cbe_intermediateHash;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds i32* %%intermediateHash, i64 1, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_334_count);
  llvm_cbe_tmp__106 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load i32* %%54, align 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_335_count);
  llvm_cbe_tmp__107 = (unsigned int )*llvm_cbe_tmp__106;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds i32* %%intermediateHash, i64 2, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_340_count);
  llvm_cbe_tmp__108 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i32* %%56, align 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__109 = (unsigned int )*llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds i32* %%intermediateHash, i64 3, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__110 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i32* %%58, align 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__111 = (unsigned int )*llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds i32* %%intermediateHash, i64 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__112 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i32* %%60, align 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__113 = (unsigned int )*llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = getelementptr inbounds i32* %%intermediateHash, i64 5, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__114 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i32* %%62, align 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__115 = (unsigned int )*llvm_cbe_tmp__114;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds i32* %%intermediateHash, i64 6, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__116 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load i32* %%64, align 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__117 = (unsigned int )*llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = getelementptr inbounds i32* %%intermediateHash, i64 7, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__118 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = load i32* %%66, align 4, !dbg !10 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__119 = (unsigned int )*llvm_cbe_tmp__118;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__119);
  llvm_cbe_storemerge311__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  llvm_cbe_tmp__120__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__105;   /* for PHI node */
  llvm_cbe_tmp__121__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__107;   /* for PHI node */
  llvm_cbe_tmp__122__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__109;   /* for PHI node */
  llvm_cbe_tmp__123__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__111;   /* for PHI node */
  llvm_cbe_tmp__124__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__113;   /* for PHI node */
  llvm_cbe_tmp__125__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__115;   /* for PHI node */
  llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__117;   /* for PHI node */
  llvm_cbe_tmp__127__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__119;   /* for PHI node */
  goto llvm_cbe_tmp__163;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__163:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge311 = phi i7 [ 0, %%52 ], [ %%101, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_storemerge311_count);
  llvm_cbe_storemerge311 = (unsigned char )llvm_cbe_storemerge311__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge311 = 0x%X",llvm_cbe_storemerge311);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__152);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = phi i32 [ %%53, %%52 ], [ %%91, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_402_count);
  llvm_cbe_tmp__120 = (unsigned int )llvm_cbe_tmp__120__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__120);
printf("\n = 0x%X",llvm_cbe_tmp__105);
printf("\n = 0x%X",llvm_cbe_tmp__142);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = phi i32 [ %%55, %%52 ], [ %%69, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__121 = (unsigned int )llvm_cbe_tmp__121__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__121);
printf("\n = 0x%X",llvm_cbe_tmp__107);
printf("\n = 0x%X",llvm_cbe_tmp__120);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = phi i32 [ %%57, %%52 ], [ %%98, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_404_count);
  llvm_cbe_tmp__122 = (unsigned int )llvm_cbe_tmp__122__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__122);
printf("\n = 0x%X",llvm_cbe_tmp__109);
printf("\n = 0x%X",llvm_cbe_tmp__149);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = phi i32 [ %%59, %%52 ], [ %%71, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_405_count);
  llvm_cbe_tmp__123 = (unsigned int )llvm_cbe_tmp__123__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__123);
printf("\n = 0x%X",llvm_cbe_tmp__111);
printf("\n = 0x%X",llvm_cbe_tmp__122);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = phi i32 [ %%61, %%52 ], [ %%100, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_406_count);
  llvm_cbe_tmp__124 = (unsigned int )llvm_cbe_tmp__124__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__124);
printf("\n = 0x%X",llvm_cbe_tmp__113);
printf("\n = 0x%X",llvm_cbe_tmp__151);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = phi i32 [ %%63, %%52 ], [ %%73, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_407_count);
  llvm_cbe_tmp__125 = (unsigned int )llvm_cbe_tmp__125__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__125);
printf("\n = 0x%X",llvm_cbe_tmp__115);
printf("\n = 0x%X",llvm_cbe_tmp__124);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = phi i32 [ %%65, %%52 ], [ %%99, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_408_count);
  llvm_cbe_tmp__126 = (unsigned int )llvm_cbe_tmp__126__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__126);
printf("\n = 0x%X",llvm_cbe_tmp__117);
printf("\n = 0x%X",llvm_cbe_tmp__150);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = phi i32 [ %%67, %%52 ], [ %%75, %%68  for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_409_count);
  llvm_cbe_tmp__127 = (unsigned int )llvm_cbe_tmp__127__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__127);
printf("\n = 0x%X",llvm_cbe_tmp__119);
printf("\n = 0x%X",llvm_cbe_tmp__126);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = call i32 @LeftRotate(i32 %%69, i6 zeroext 12), !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_410_count);
  llvm_cbe_tmp__128 = (unsigned int )LeftRotate(llvm_cbe_tmp__120, ((unsigned char )12));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__120);
printf("\nArgument  = 0x%X",((unsigned char )12));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__128);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = call i32 @T(i7 zeroext %%storemerge311), !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_411_count);
  llvm_cbe_tmp__129 = (unsigned int )T(llvm_cbe_storemerge311);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge311 = 0x%X",llvm_cbe_storemerge311);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__129);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = trunc i7 %%storemerge311 to i6, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_412_count);
  llvm_cbe_tmp__130 = (unsigned char )((unsigned char )llvm_cbe_storemerge311&63U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = call i32 @LeftRotate(i32 %%78, i6 zeroext %%79), !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_413_count);
  llvm_cbe_tmp__131 = (unsigned int )LeftRotate(llvm_cbe_tmp__129, llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__129);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__130);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__131);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = add i32 %%77, %%73, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_414_count);
  llvm_cbe_tmp__132 = (unsigned int )((unsigned int )(llvm_cbe_tmp__128&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__124&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__132&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = add i32 %%81, %%80, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_415_count);
  llvm_cbe_tmp__133 = (unsigned int )((unsigned int )(llvm_cbe_tmp__132&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__131&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__133&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = call i32 @LeftRotate(i32 %%82, i6 zeroext 7), !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_416_count);
  llvm_cbe_tmp__134 = (unsigned int )LeftRotate(llvm_cbe_tmp__133, ((unsigned char )7));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__133);
printf("\nArgument  = 0x%X",((unsigned char )7));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__134);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = xor i32 %%83, %%77, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_420_count);
  llvm_cbe_tmp__135 = (unsigned int )llvm_cbe_tmp__134 ^ llvm_cbe_tmp__128;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = call i32 @FF(i32 %%69, i32 %%70, i32 %%71, i7 zeroext %%storemerge311), !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_423_count);
  llvm_cbe_tmp__136 = (unsigned int )FF(llvm_cbe_tmp__120, llvm_cbe_tmp__121, llvm_cbe_tmp__122, llvm_cbe_storemerge311);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__120);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__121);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__122);
printf("\nArgument storemerge311 = 0x%X",llvm_cbe_storemerge311);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__136);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = zext i7 %%storemerge311 to i64, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_424_count);
  llvm_cbe_tmp__137 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge311&127U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = getelementptr inbounds [64 x i32]* %%W_, i64 0, i64 %%86, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_425_count);
  llvm_cbe_tmp__138 = (signed int *)(&llvm_cbe_W_[(((signed long long )llvm_cbe_tmp__137))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__137));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__137) < 64)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W_' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = load i32* %%87, align 4, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_426_count);
  llvm_cbe_tmp__139 = (unsigned int )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = add i32 %%84, %%72, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_427_count);
  llvm_cbe_tmp__140 = (unsigned int )((unsigned int )(llvm_cbe_tmp__135&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__123&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__140&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = add i32 %%89, %%85, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_428_count);
  llvm_cbe_tmp__141 = (unsigned int )((unsigned int )(llvm_cbe_tmp__140&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__136&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__141&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = add i32 %%90, %%88, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_429_count);
  llvm_cbe_tmp__142 = (unsigned int )((unsigned int )(llvm_cbe_tmp__141&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__139&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__142&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = call i32 @GG(i32 %%73, i32 %%74, i32 %%75, i7 zeroext %%storemerge311), !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__143 = (unsigned int )GG(llvm_cbe_tmp__124, llvm_cbe_tmp__125, llvm_cbe_tmp__126, llvm_cbe_storemerge311);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__124);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__125);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__126);
printf("\nArgument storemerge311 = 0x%X",llvm_cbe_storemerge311);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__143);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = getelementptr inbounds [68 x i32]* %%W, i64 0, i64 %%86, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_433_count);
  llvm_cbe_tmp__144 = (signed int *)(&llvm_cbe_W[(((signed long long )llvm_cbe_tmp__137))
#ifdef AESL_BC_SIM
 % 68
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__137));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__137) < 68)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = load i32* %%93, align 4, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__145 = (unsigned int )*llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = add i32 %%83, %%76, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_435_count);
  llvm_cbe_tmp__146 = (unsigned int )((unsigned int )(llvm_cbe_tmp__134&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__127&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__146&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = add i32 %%95, %%92, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__147 = (unsigned int )((unsigned int )(llvm_cbe_tmp__146&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__143&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__147&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = add i32 %%96, %%94, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__148 = (unsigned int )((unsigned int )(llvm_cbe_tmp__147&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__145&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__148&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = call i32 @LeftRotate(i32 %%70, i6 zeroext 9), !dbg !16 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__149 = (unsigned int )LeftRotate(llvm_cbe_tmp__121, ((unsigned char )9));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__121);
printf("\nArgument  = 0x%X",((unsigned char )9));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__149);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = call i32 @LeftRotate(i32 %%74, i6 zeroext 19), !dbg !16 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__150 = (unsigned int )LeftRotate(llvm_cbe_tmp__125, ((unsigned char )19));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__125);
printf("\nArgument  = 0x%X",((unsigned char )19));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__150);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = call i32 @P0(i32 %%97), !dbg !17 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__151 = (unsigned int )P0(llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__148);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__151);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = add i7 %%storemerge311, 1, !dbg !15 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__152 = (unsigned char )((unsigned char )(llvm_cbe_storemerge311&127ull)) + ((unsigned char )(((unsigned char )1)&127ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__152&127ull)));
  if (((llvm_cbe_tmp__152&127U) == (((unsigned char )64u)&127U))) {
    goto llvm_cbe_tmp__164;
  } else {
    llvm_cbe_storemerge311__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__152;   /* for PHI node */
    llvm_cbe_tmp__120__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__142;   /* for PHI node */
    llvm_cbe_tmp__121__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__120;   /* for PHI node */
    llvm_cbe_tmp__122__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__149;   /* for PHI node */
    llvm_cbe_tmp__123__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__122;   /* for PHI node */
    llvm_cbe_tmp__124__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__151;   /* for PHI node */
    llvm_cbe_tmp__125__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__124;   /* for PHI node */
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__150;   /* for PHI node */
    llvm_cbe_tmp__127__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__126;   /* for PHI node */
    goto llvm_cbe_tmp__163;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__164:
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = xor i32 %%53, %%91, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_481_count);
  llvm_cbe_tmp__153 = (unsigned int )llvm_cbe_tmp__105 ^ llvm_cbe_tmp__142;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%103, i32* %%intermediateHash, align 4, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_482_count);
  *llvm_cbe_intermediateHash = llvm_cbe_tmp__153;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = xor i32 %%55, %%69, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__154 = (unsigned int )llvm_cbe_tmp__107 ^ llvm_cbe_tmp__120;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%104, i32* %%54, align 4, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_484_count);
  *llvm_cbe_tmp__106 = llvm_cbe_tmp__154;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = xor i32 %%57, %%98, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_485_count);
  llvm_cbe_tmp__155 = (unsigned int )llvm_cbe_tmp__109 ^ llvm_cbe_tmp__149;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__155);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%105, i32* %%56, align 4, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_486_count);
  *llvm_cbe_tmp__108 = llvm_cbe_tmp__155;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__155);
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = xor i32 %%59, %%71, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_487_count);
  llvm_cbe_tmp__156 = (unsigned int )llvm_cbe_tmp__111 ^ llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__156);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%106, i32* %%58, align 4, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_488_count);
  *llvm_cbe_tmp__110 = llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__156);
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = xor i32 %%61, %%100, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_489_count);
  llvm_cbe_tmp__157 = (unsigned int )llvm_cbe_tmp__113 ^ llvm_cbe_tmp__151;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%107, i32* %%60, align 4, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_490_count);
  *llvm_cbe_tmp__112 = llvm_cbe_tmp__157;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = xor i32 %%63, %%73, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_491_count);
  llvm_cbe_tmp__158 = (unsigned int )llvm_cbe_tmp__115 ^ llvm_cbe_tmp__124;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%108, i32* %%62, align 4, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_492_count);
  *llvm_cbe_tmp__114 = llvm_cbe_tmp__158;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = xor i32 %%65, %%99, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_493_count);
  llvm_cbe_tmp__159 = (unsigned int )llvm_cbe_tmp__117 ^ llvm_cbe_tmp__150;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%109, i32* %%64, align 4, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_494_count);
  *llvm_cbe_tmp__116 = llvm_cbe_tmp__159;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = xor i32 %%67, %%75, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_495_count);
  llvm_cbe_tmp__160 = (unsigned int )llvm_cbe_tmp__119 ^ llvm_cbe_tmp__126;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__160);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%110, i32* %%66, align 4, !dbg !11 for 0x%I64xth hint within @processmessageblock  --> \n", ++aesl_llvm_cbe_496_count);
  *llvm_cbe_tmp__118 = llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__160);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @processmessageblock}\n");
  return;
}


static ap_private<512, true> llvm_part_set_i512_i8(ap_private<512, true> llvm_cbe_Val,  char llvm_cbe_Rep, signed int llvm_cbe_Lo, signed int llvm_cbe_Hi) __ATTRIBUTE_WEAK__;

static ap_private<512, true> llvm_part_set_i512_i32(ap_private<512, true> llvm_cbe_Val, signed int llvm_cbe_Rep, signed int llvm_cbe_Lo, signed int llvm_cbe_Hi) __ATTRIBUTE_WEAK__;

static ap_private<512, true> llvm_part_select_i512(ap_private<512, true> llvm_cbe_Val, signed int llvm_cbe_Lo, signed int llvm_cbe_High) __ATTRIBUTE_WEAK__;

void SM3Calc( char *llvm_cbe_message,  char llvm_cbe_messageLen, signed int *llvm_cbe_digest) {
  static  unsigned long long aesl_llvm_cbe_messageBlock_count = 0;
  signed int llvm_cbe_messageBlock[16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_intermediateHash_count = 0;
  signed int llvm_cbe_intermediateHash[8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned char llvm_cbe_storemerge7;
  unsigned char llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  ap_private<512, false> llvm_cbe_tmp__165;
  ap_private<512, false> llvm_cbe_tmp__165__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  unsigned long long llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
   char *llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  unsigned char llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  unsigned int llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  unsigned int llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  unsigned int llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  ap_private<512, false> llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  unsigned char llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  unsigned int llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  unsigned int llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  ap_private<512, false> llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  ap_private<512, false> llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  unsigned int llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  ap_private<512, false> llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  ap_private<512, false> llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge16_count = 0;
  unsigned char llvm_cbe_storemerge16;
  unsigned char llvm_cbe_storemerge16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  unsigned int llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  unsigned int llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  unsigned int llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  ap_private<512, false> llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  unsigned int llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  unsigned long long llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  signed int *llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  unsigned char llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond8_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned char llvm_cbe_storemerge25;
  unsigned char llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  unsigned int llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  unsigned int llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  unsigned long long llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  signed int *llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  unsigned int llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  unsigned int llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  unsigned char llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  signed int *llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  signed int *llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  signed int *llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  unsigned int llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  signed int *llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  unsigned int llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  signed int *llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  signed int *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  unsigned int llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  signed int *llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  signed int *llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  unsigned int llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  signed int *llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  signed int *llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  unsigned int llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  signed int *llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  signed int *llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  unsigned int llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  signed int *llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  signed int *llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  unsigned int llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  signed int *llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  unsigned int llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  signed int *llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @SM3Calc\n");
  llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  llvm_cbe_tmp__165__PHI_TEMPORARY = (ap_private<512, false> )((ap_private<512, false> )0u);   /* for PHI node */
  goto llvm_cbe_tmp__220;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__220:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i6 [ 0, %%0 ], [ %%10, %%1  for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned char )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%X",llvm_cbe_storemerge7);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__173);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i512 [ 0, %%0 ], [ %%9, %%1  for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__165 = (ap_private<512, false> )llvm_cbe_tmp__165__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %s",llvm_cbe_tmp__165.to_string().c_str());
printf("\n = %s",((ap_private<512, false> )0u).to_string().c_str());
printf("\n = %s",llvm_cbe_tmp__172.to_string().c_str());
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i6 %%storemerge7 to i64, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__166 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge7&63U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__166);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%message, i64 %%3, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_548_count);
  llvm_cbe_tmp__167 = ( char *)(&llvm_cbe_message[(((signed long long )llvm_cbe_tmp__166))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__166));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_549_count);
  llvm_cbe_tmp__168 = (unsigned char )*llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__168);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i6 %%storemerge7 to i32, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_552_count);
  llvm_cbe_tmp__169 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge7&63U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl nuw nsw i32 %%6, 3, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_553_count);
  llvm_cbe_tmp__170 = (unsigned int )llvm_cbe_tmp__169 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = or i32 %%7, 7, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_554_count);
  llvm_cbe_tmp__171 = (unsigned int )llvm_cbe_tmp__170 | 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i512 @llvm_part_set_i512_i8(i512 %%2, i8 %%5, i32 %%7, i32 %%8 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_555_count);
  llvm_cbe_tmp__172 = (ap_private<512, false> )llvm_part_set_i512_i8(llvm_cbe_tmp__165, llvm_cbe_tmp__168, llvm_cbe_tmp__170, llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %s",llvm_cbe_tmp__165.to_string().c_str());
printf("\nArgument  = 0x%X",llvm_cbe_tmp__168);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__170);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__171);
printf("\nReturn  = %s",llvm_cbe_tmp__172.to_string().c_str());
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i6 %%storemerge7, 1, !dbg !13 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_557_count);
  llvm_cbe_tmp__173 = (unsigned char )((unsigned char )(llvm_cbe_storemerge7&63ull)) + ((unsigned char )(((unsigned char )1)&63ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__173&63ull)));
  if (((llvm_cbe_tmp__173&63U) == (((unsigned char )32u)&63U))) {
    goto llvm_cbe_tmp__221;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__173;   /* for PHI node */
    llvm_cbe_tmp__165__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__172;   /* for PHI node */
    goto llvm_cbe_tmp__220;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__221:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i8 %%messageLen to i32, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_585_count);
  llvm_cbe_tmp__174 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_messageLen&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__174);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sub nsw i32 512, %%12, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__175 = (unsigned int )((unsigned int )(512u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__174&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__175&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i512, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__176 = (ap_private<512, false> )((ap_private<512, false> )(unsigned int )llvm_cbe_tmp__175&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = %s\n", llvm_cbe_tmp__176.to_string().c_str());
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl i512 %%9, %%14, !dbg !10 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__177 = (ap_private<512, false> )llvm_cbe_tmp__172 << llvm_cbe_tmp__176;
if (AESL_DEBUG_TRACE)
printf("\n = %s\n", llvm_cbe_tmp__177.to_string().c_str());
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = xor i32 %%12, 511, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_603_count);
  llvm_cbe_tmp__178 = (unsigned int )llvm_cbe_tmp__174 ^ 511u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call i512 @llvm_part_set_i512_i32(i512 %%15, i32 1, i32 %%16, i32 %%16 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_604_count);
  llvm_cbe_tmp__179 = (ap_private<512, false> )llvm_part_set_i512_i32(llvm_cbe_tmp__177, 1u, llvm_cbe_tmp__178, llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %s",llvm_cbe_tmp__177.to_string().c_str());
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__178);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__178);
printf("\nReturn  = %s",llvm_cbe_tmp__179.to_string().c_str());
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i512 @llvm_part_set_i512_i8(i512 %%17, i8 %%messageLen, i32 0, i32 7 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_620_count);
  llvm_cbe_tmp__180 = (ap_private<512, false> )llvm_part_set_i512_i8(llvm_cbe_tmp__179, llvm_cbe_messageLen, 0u, 7u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %s",llvm_cbe_tmp__179.to_string().c_str());
printf("\nArgument messageLen = 0x%X",llvm_cbe_messageLen);
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%X",7u);
printf("\nReturn  = %s",llvm_cbe_tmp__180.to_string().c_str());
}
  llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe_tmp__222;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__222:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge16 = phi i6 [ 0, %%11 ], [ %%30, %%24  for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_storemerge16_count);
  llvm_cbe_storemerge16 = (unsigned char )llvm_cbe_storemerge16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%X",llvm_cbe_storemerge16);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__188);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i6 %%storemerge16 to i32, !dbg !13 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_656_count);
  llvm_cbe_tmp__181 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge16&63U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__181);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = shl nuw nsw i32 %%20, 5, !dbg !13 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_657_count);
  llvm_cbe_tmp__182 = (unsigned int )llvm_cbe_tmp__181 << 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__182);
  if ((((unsigned int )llvm_cbe_tmp__182&4294967295U) < ((unsigned int )512u&4294967295U))) {
    goto llvm_cbe_tmp__223;
  } else {
    goto llvm_cbe_tmp__224;
  }

llvm_cbe_tmp__223:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = or i32 %%21, 31, !dbg !12 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_667_count);
  llvm_cbe_tmp__183 = (unsigned int )llvm_cbe_tmp__182 | 31u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i512 @llvm_part_select_i512(i512 %%18, i32 %%21, i32 %%25 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_668_count);
  llvm_cbe_tmp__184 = (ap_private<512, false> )llvm_part_select_i512(llvm_cbe_tmp__180, llvm_cbe_tmp__182, llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %s",llvm_cbe_tmp__180.to_string().c_str());
printf("\nArgument  = 0x%X",llvm_cbe_tmp__182);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__183);
printf("\nReturn  = %s",llvm_cbe_tmp__184.to_string().c_str());
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = trunc i512 %%26 to i32, !dbg !12 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_671_count);
  llvm_cbe_tmp__185 = (unsigned int )((unsigned int )llvm_cbe_tmp__184.to_uint64()&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = zext i6 %%storemerge16 to i64, !dbg !12 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_672_count);
  llvm_cbe_tmp__186 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge16&63U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__186);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [16 x i32]* %%messageBlock, i64 0, i64 %%28, !dbg !12 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_673_count);
  llvm_cbe_tmp__187 = (signed int *)(&llvm_cbe_messageBlock[(((signed long long )llvm_cbe_tmp__186))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__186));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__186) < 16 && "Write access out of array 'messageBlock' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%27, i32* %%29, align 4, !dbg !12 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_674_count);
  *llvm_cbe_tmp__187 = llvm_cbe_tmp__185;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i6 %%storemerge16, 1, !dbg !14 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_675_count);
  llvm_cbe_tmp__188 = (unsigned char )((unsigned char )(llvm_cbe_storemerge16&63ull)) + ((unsigned char )(((unsigned char )1)&63ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__188&63ull)));
  if (((llvm_cbe_tmp__188&63U) == (((unsigned char )16)&63U))) {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__188;   /* for PHI node */
    goto llvm_cbe_tmp__222;
  }

llvm_cbe_tmp__224:
if (AESL_DEBUG_TRACE)
printf("\n  call void @_assert(i8* getelementptr inbounds ([155 x i8]* @aesl_internal_.str5, i64 0, i64 0), i8* getelementptr inbounds ([40 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 224) nounwind, !dbg !15 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_660_count);
  _assert(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 155
#endif
])), ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 40
#endif
])), 224u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",224u);
}
  goto llvm_cbe_tmp__223;

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i6 [ %%37, %%.preheader ], [ 0, %%24  for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned char )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\n = 0x%X",llvm_cbe_tmp__195);
printf("\n = 0x%X",((unsigned char )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = zext i6 %%storemerge25 to i32, !dbg !14 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_703_count);
  llvm_cbe_tmp__189 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge25&63U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = sub nsw i32 15, %%31, !dbg !14 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__190 = (unsigned int )((unsigned int )(15u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__189&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__190&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%32 to i64, !dbg !14 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__191 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [16 x i32]* %%messageBlock, i64 0, i64 %%33, !dbg !14 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_706_count);
  llvm_cbe_tmp__192 = (signed int *)(&llvm_cbe_messageBlock[(((signed long long )llvm_cbe_tmp__191))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__191));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__191) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'messageBlock' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i32* %%34, align 4, !dbg !14 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_707_count);
  llvm_cbe_tmp__193 = (unsigned int )*llvm_cbe_tmp__192;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str6, i64 0, i64 0), i32 %%35) nounwind, !dbg !14 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_708_count);
  printf(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__193);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__194);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i6 %%storemerge25, 1, !dbg !14 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_709_count);
  llvm_cbe_tmp__195 = (unsigned char )((unsigned char )(llvm_cbe_storemerge25&63ull)) + ((unsigned char )(((unsigned char )1)&63ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__195&63ull)));
  if (((llvm_cbe_tmp__195&63U) == (((unsigned char )16)&63U))) {
    goto llvm_cbe_tmp__225;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__195;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__225:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [8 x i32]* %%intermediateHash, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_737_count);
  llvm_cbe_tmp__196 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initial(i32* %%39), !dbg !16 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_738_count);
  initial((signed int *)llvm_cbe_tmp__196);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds [16 x i32]* %%messageBlock, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_739_count);
  llvm_cbe_tmp__197 = (signed int *)(&llvm_cbe_messageBlock[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @processmessageblock(i32* %%39, i32* %%40), !dbg !16 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_740_count);
  processmessageblock((signed int *)llvm_cbe_tmp__196, (signed int *)llvm_cbe_tmp__197);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds [8 x i32]* %%intermediateHash, i64 0, i64 7, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_767_count);
  llvm_cbe_tmp__198 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )7ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'intermediateHash' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i32* %%41, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_768_count);
  llvm_cbe_tmp__199 = (unsigned int )*llvm_cbe_tmp__198;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%42, i32* %%digest, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_769_count);
  *llvm_cbe_digest = llvm_cbe_tmp__199;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds [8 x i32]* %%intermediateHash, i64 0, i64 6, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_796_count);
  llvm_cbe_tmp__200 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )6ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'intermediateHash' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i32* %%43, align 8, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__201 = (unsigned int )*llvm_cbe_tmp__200;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i32* %%digest, i64 1, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_798_count);
  llvm_cbe_tmp__202 = (signed int *)(&llvm_cbe_digest[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%44, i32* %%45, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_799_count);
  *llvm_cbe_tmp__202 = llvm_cbe_tmp__201;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds [8 x i32]* %%intermediateHash, i64 0, i64 5, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_826_count);
  llvm_cbe_tmp__203 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )5ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'intermediateHash' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i32* %%46, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_827_count);
  llvm_cbe_tmp__204 = (unsigned int )*llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__204);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds i32* %%digest, i64 2, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_828_count);
  llvm_cbe_tmp__205 = (signed int *)(&llvm_cbe_digest[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%47, i32* %%48, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_829_count);
  *llvm_cbe_tmp__205 = llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__204);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds [8 x i32]* %%intermediateHash, i64 0, i64 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_856_count);
  llvm_cbe_tmp__206 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )4ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'intermediateHash' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i32* %%49, align 16, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_857_count);
  llvm_cbe_tmp__207 = (unsigned int )*llvm_cbe_tmp__206;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds i32* %%digest, i64 3, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_858_count);
  llvm_cbe_tmp__208 = (signed int *)(&llvm_cbe_digest[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%50, i32* %%51, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_859_count);
  *llvm_cbe_tmp__208 = llvm_cbe_tmp__207;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds [8 x i32]* %%intermediateHash, i64 0, i64 3, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_886_count);
  llvm_cbe_tmp__209 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'intermediateHash' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load i32* %%52, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__210 = (unsigned int )*llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__210);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds i32* %%digest, i64 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_888_count);
  llvm_cbe_tmp__211 = (signed int *)(&llvm_cbe_digest[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%53, i32* %%54, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_889_count);
  *llvm_cbe_tmp__211 = llvm_cbe_tmp__210;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__210);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds [8 x i32]* %%intermediateHash, i64 0, i64 2, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_916_count);
  llvm_cbe_tmp__212 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'intermediateHash' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i32* %%55, align 8, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_917_count);
  llvm_cbe_tmp__213 = (unsigned int )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__213);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds i32* %%digest, i64 5, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_918_count);
  llvm_cbe_tmp__214 = (signed int *)(&llvm_cbe_digest[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%56, i32* %%57, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_919_count);
  *llvm_cbe_tmp__214 = llvm_cbe_tmp__213;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__213);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds [8 x i32]* %%intermediateHash, i64 0, i64 1, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_946_count);
  llvm_cbe_tmp__215 = (signed int *)(&llvm_cbe_intermediateHash[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'intermediateHash' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i32* %%58, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_947_count);
  llvm_cbe_tmp__216 = (unsigned int )*llvm_cbe_tmp__215;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__216);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds i32* %%digest, i64 6, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_948_count);
  llvm_cbe_tmp__217 = (signed int *)(&llvm_cbe_digest[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%59, i32* %%60, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_949_count);
  *llvm_cbe_tmp__217 = llvm_cbe_tmp__216;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__216);

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'intermediateHash' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i32* %%39, align 16, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_976_count);
  llvm_cbe_tmp__218 = (unsigned int )*llvm_cbe_tmp__196;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__218);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = getelementptr inbounds i32* %%digest, i64 7, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_977_count);
  llvm_cbe_tmp__219 = (signed int *)(&llvm_cbe_digest[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%61, i32* %%62, align 4, !dbg !11 for 0x%I64xth hint within @SM3Calc  --> \n", ++aesl_llvm_cbe_978_count);
  *llvm_cbe_tmp__219 = llvm_cbe_tmp__218;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__218);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @SM3Calc}\n");
  return;
}


ap_private<512, true> llvm_part_set_i512_i8(ap_private<512, true> llvm_cbe_Val,  char llvm_cbe_Rep, signed int llvm_cbe_Lo, signed int llvm_cbe_Hi) {
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  unsigned int llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  unsigned int llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  unsigned int llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  unsigned int llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  ap_private<512, false> llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  unsigned int llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  unsigned char llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  unsigned char llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  unsigned char llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  unsigned char llvm_cbe_tmp__235;
  unsigned char llvm_cbe_tmp__235__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  ap_private<512, false> llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_count_count = 0;
  unsigned int llvm_cbe_count;
  unsigned int llvm_cbe_count__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_val_count = 0;
  ap_private<512, false> llvm_cbe_val;
  ap_private<512, false> llvm_cbe_val__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_rres_count = 0;
  ap_private<512, false> llvm_cbe_rres;
  ap_private<512, false> llvm_cbe_rres__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  unsigned int llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  ap_private<512, false> llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  ap_private<512, false> llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  ap_private<512, false> llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  ap_private<512, false> llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  ap_private<512, false> llvm_cbe_tmp__242;
  ap_private<512, false> llvm_cbe_tmp__242__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  ap_private<512, false> llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  ap_private<512, false> llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  ap_private<512, false> llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  ap_private<512, false> llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  ap_private<512, false> llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  ap_private<512, false> llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  ap_private<512, false> llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  ap_private<512, false> llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_part_set_count = 0;
  ap_private<512, false> llvm_cbe_part_set;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;

 if (!(llvm_cbe_Lo < 512 && llvm_cbe_Hi < 512))
   fprintf(stderr, "%s:%d: warning: Part set out of range.\n", __FILE__, __LINE__);
  llvm_cbe_tmp__226 = (unsigned int )(((((unsigned int )llvm_cbe_Lo&4294967295U) < ((unsigned int )llvm_cbe_Hi&4294967295U))) ? ((unsigned int )llvm_cbe_Hi) : ((unsigned int )llvm_cbe_Lo));
  llvm_cbe_tmp__227 = (unsigned int )(((((unsigned int )llvm_cbe_Lo&4294967295U) < ((unsigned int )llvm_cbe_Hi&4294967295U))) ? ((unsigned int )llvm_cbe_Lo) : ((unsigned int )llvm_cbe_Hi));
  llvm_cbe_tmp__228 = (unsigned int )((unsigned int )(llvm_cbe_tmp__226&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__227&4294967295ull));
  llvm_cbe_tmp__229 = (unsigned int )((unsigned int )(llvm_cbe_tmp__228&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
  llvm_cbe_tmp__230 = (ap_private<512, false> )((ap_private<512, false> )(unsigned int )llvm_cbe_tmp__227&4294967295U);
  if ((((unsigned int )llvm_cbe_tmp__229&4294967295U) < ((unsigned int )8u&4294967295U))) {
    goto llvm_cbe_large;
  } else {
    llvm_cbe_tmp__235__PHI_TEMPORARY = (unsigned char )llvm_cbe_Rep;   /* for PHI node */
    goto llvm_cbe_small;
  }

llvm_cbe_large:
  llvm_cbe_tmp__231 = (unsigned int )((unsigned int )(8u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__229&4294967295ull));
  llvm_cbe_tmp__232 = (unsigned char )((unsigned char )llvm_cbe_tmp__231&255U);
  llvm_cbe_tmp__233 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(((unsigned char )-1)&255ull)) >> ((unsigned char )(llvm_cbe_tmp__232&255ull))))));
  llvm_cbe_tmp__234 = (unsigned char )((unsigned char )(llvm_cbe_tmp__233 & llvm_cbe_Rep));
  llvm_cbe_tmp__235__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__234;   /* for PHI node */
  goto llvm_cbe_small;

llvm_cbe_small:
  llvm_cbe_tmp__235 = (unsigned char )llvm_cbe_tmp__235__PHI_TEMPORARY;
  llvm_cbe_tmp__236 = (ap_private<512, false> )((ap_private<512, false> )(unsigned char )llvm_cbe_tmp__235&255U);
  if ((((unsigned int )llvm_cbe_Lo&4294967295U) < ((unsigned int )llvm_cbe_Hi&4294967295U))) {
    llvm_cbe_tmp__242__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__236;   /* for PHI node */
    goto llvm_cbe_result;
  } else {
    llvm_cbe_count__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__229;   /* for PHI node */
    llvm_cbe_val__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__236;   /* for PHI node */
    llvm_cbe_rres__PHI_TEMPORARY = (ap_private<512, false> )((ap_private<512, false> )0u);   /* for PHI node */
    goto llvm_cbe_reverse;
  }

  do {     /* Syntactic loop 'reverse' to make GCC happy */
llvm_cbe_reverse:
  llvm_cbe_count = (unsigned int )llvm_cbe_count__PHI_TEMPORARY;
  llvm_cbe_val = (ap_private<512, false> )llvm_cbe_val__PHI_TEMPORARY;
  llvm_cbe_rres = (ap_private<512, false> )llvm_cbe_rres__PHI_TEMPORARY;
  llvm_cbe_tmp__237 = (unsigned int )((unsigned int )(llvm_cbe_count&4294967295ull)) - ((unsigned int )(1u&4294967295ull));
  llvm_cbe_tmp__238 = (ap_private<512, false> )llvm_cbe_val & ((ap_private<512, false> )1u);
  llvm_cbe_tmp__239 = (ap_private<512, false> )((ap_private<512, false> )(((ap_private<512, false> )llvm_cbe_val) >> ((ap_private<512, false> )((ap_private<512, false> )1u))));
  llvm_cbe_tmp__240 = (ap_private<512, false> )llvm_cbe_rres << ((ap_private<512, false> )1u);
  llvm_cbe_tmp__241 = (ap_private<512, false> )llvm_cbe_tmp__240 | llvm_cbe_tmp__238;
  if (((llvm_cbe_tmp__237&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__242__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__241;   /* for PHI node */
    goto llvm_cbe_result;
  } else {
    llvm_cbe_count__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__237;   /* for PHI node */
    llvm_cbe_val__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__239;   /* for PHI node */
    llvm_cbe_rres__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__241;   /* for PHI node */
    goto llvm_cbe_reverse;
  }

  } while (1); /* end of syntactic loop 'reverse' */
llvm_cbe_result:
  llvm_cbe_tmp__242 = (ap_private<512, false> )llvm_cbe_tmp__242__PHI_TEMPORARY;
  llvm_cbe_tmp__243 = (ap_private<512, false> )((ap_private<512, false> )(unsigned int )llvm_cbe_tmp__229&4294967295U);
  llvm_cbe_tmp__244 = (ap_private<512, false> )((ap_private<512, false> )-1ll) << llvm_cbe_tmp__230;
  llvm_cbe_tmp__245 = (ap_private<512, false> )llvm_cbe_tmp__244 ^ ((ap_private<512, false> )-1ll);
  llvm_cbe_tmp__246 = (ap_private<512, false> )llvm_cbe_tmp__244 << llvm_cbe_tmp__243;
  llvm_cbe_tmp__247 = (ap_private<512, false> )(((((unsigned int )llvm_cbe_tmp__229&4294967295U) >= ((unsigned int )512u&4294967295U))) ? ((ap_private<512, false> )((ap_private<512, false> )0u)) : ((ap_private<512, false> )llvm_cbe_tmp__246));
  llvm_cbe_tmp__248 = (ap_private<512, false> )llvm_cbe_tmp__245 | llvm_cbe_tmp__247;
  llvm_cbe_tmp__249 = (ap_private<512, false> )llvm_cbe_tmp__248 & llvm_cbe_Val;
  llvm_cbe_tmp__250 = (ap_private<512, false> )llvm_cbe_tmp__242 << llvm_cbe_tmp__230;
  llvm_cbe_part_set = (ap_private<512, false> )llvm_cbe_tmp__249 | llvm_cbe_tmp__250;
  return llvm_cbe_part_set;
}


ap_private<512, true> llvm_part_set_i512_i32(ap_private<512, true> llvm_cbe_Val, signed int llvm_cbe_Rep, signed int llvm_cbe_Lo, signed int llvm_cbe_Hi) {
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  unsigned int llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  unsigned int llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  unsigned int llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  unsigned int llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  ap_private<512, false> llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  unsigned int llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  unsigned int llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  unsigned int llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  unsigned int llvm_cbe_tmp__259;
  unsigned int llvm_cbe_tmp__259__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  ap_private<512, false> llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe_count_count = 0;
  unsigned int llvm_cbe_count;
  unsigned int llvm_cbe_count__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_val_count = 0;
  ap_private<512, false> llvm_cbe_val;
  ap_private<512, false> llvm_cbe_val__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_rres_count = 0;
  ap_private<512, false> llvm_cbe_rres;
  ap_private<512, false> llvm_cbe_rres__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  unsigned int llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  ap_private<512, false> llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  ap_private<512, false> llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  ap_private<512, false> llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  ap_private<512, false> llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  ap_private<512, false> llvm_cbe_tmp__266;
  ap_private<512, false> llvm_cbe_tmp__266__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  ap_private<512, false> llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  ap_private<512, false> llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  ap_private<512, false> llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  ap_private<512, false> llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  ap_private<512, false> llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  ap_private<512, false> llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  ap_private<512, false> llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  ap_private<512, false> llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_part_set_count = 0;
  ap_private<512, false> llvm_cbe_part_set;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;

 if (!(llvm_cbe_Lo < 512 && llvm_cbe_Hi < 512))
   fprintf(stderr, "%s:%d: warning: Part set out of range.\n", __FILE__, __LINE__);
  llvm_cbe_tmp__251 = (unsigned int )(((((unsigned int )llvm_cbe_Lo&4294967295U) < ((unsigned int )llvm_cbe_Hi&4294967295U))) ? ((unsigned int )llvm_cbe_Hi) : ((unsigned int )llvm_cbe_Lo));
  llvm_cbe_tmp__252 = (unsigned int )(((((unsigned int )llvm_cbe_Lo&4294967295U) < ((unsigned int )llvm_cbe_Hi&4294967295U))) ? ((unsigned int )llvm_cbe_Lo) : ((unsigned int )llvm_cbe_Hi));
  llvm_cbe_tmp__253 = (unsigned int )((unsigned int )(llvm_cbe_tmp__251&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__252&4294967295ull));
  llvm_cbe_tmp__254 = (unsigned int )((unsigned int )(llvm_cbe_tmp__253&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
  llvm_cbe_tmp__255 = (ap_private<512, false> )((ap_private<512, false> )(unsigned int )llvm_cbe_tmp__252&4294967295U);
  if ((((unsigned int )llvm_cbe_tmp__254&4294967295U) < ((unsigned int )32u&4294967295U))) {
    goto llvm_cbe_large;
  } else {
    llvm_cbe_tmp__259__PHI_TEMPORARY = (unsigned int )llvm_cbe_Rep;   /* for PHI node */
    goto llvm_cbe_small;
  }

llvm_cbe_large:
  llvm_cbe_tmp__256 = (unsigned int )((unsigned int )(32u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__254&4294967295ull));
  llvm_cbe_tmp__257 = (unsigned int )((unsigned int )(((unsigned int )(4294967295u&4294967295ull)) >> ((unsigned int )(llvm_cbe_tmp__256&4294967295ull))));
  llvm_cbe_tmp__258 = (unsigned int )llvm_cbe_tmp__257 & llvm_cbe_Rep;
  llvm_cbe_tmp__259__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__258;   /* for PHI node */
  goto llvm_cbe_small;

llvm_cbe_small:
  llvm_cbe_tmp__259 = (unsigned int )llvm_cbe_tmp__259__PHI_TEMPORARY;
  llvm_cbe_tmp__260 = (ap_private<512, false> )((ap_private<512, false> )(unsigned int )llvm_cbe_tmp__259&4294967295U);
  if ((((unsigned int )llvm_cbe_Lo&4294967295U) < ((unsigned int )llvm_cbe_Hi&4294967295U))) {
    llvm_cbe_tmp__266__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__260;   /* for PHI node */
    goto llvm_cbe_result;
  } else {
    llvm_cbe_count__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__254;   /* for PHI node */
    llvm_cbe_val__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__260;   /* for PHI node */
    llvm_cbe_rres__PHI_TEMPORARY = (ap_private<512, false> )((ap_private<512, false> )0u);   /* for PHI node */
    goto llvm_cbe_reverse;
  }

  do {     /* Syntactic loop 'reverse' to make GCC happy */
llvm_cbe_reverse:
  llvm_cbe_count = (unsigned int )llvm_cbe_count__PHI_TEMPORARY;
  llvm_cbe_val = (ap_private<512, false> )llvm_cbe_val__PHI_TEMPORARY;
  llvm_cbe_rres = (ap_private<512, false> )llvm_cbe_rres__PHI_TEMPORARY;
  llvm_cbe_tmp__261 = (unsigned int )((unsigned int )(llvm_cbe_count&4294967295ull)) - ((unsigned int )(1u&4294967295ull));
  llvm_cbe_tmp__262 = (ap_private<512, false> )llvm_cbe_val & ((ap_private<512, false> )1u);
  llvm_cbe_tmp__263 = (ap_private<512, false> )((ap_private<512, false> )(((ap_private<512, false> )llvm_cbe_val) >> ((ap_private<512, false> )((ap_private<512, false> )1u))));
  llvm_cbe_tmp__264 = (ap_private<512, false> )llvm_cbe_rres << ((ap_private<512, false> )1u);
  llvm_cbe_tmp__265 = (ap_private<512, false> )llvm_cbe_tmp__264 | llvm_cbe_tmp__262;
  if (((llvm_cbe_tmp__261&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__266__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__265;   /* for PHI node */
    goto llvm_cbe_result;
  } else {
    llvm_cbe_count__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__261;   /* for PHI node */
    llvm_cbe_val__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__263;   /* for PHI node */
    llvm_cbe_rres__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp__265;   /* for PHI node */
    goto llvm_cbe_reverse;
  }

  } while (1); /* end of syntactic loop 'reverse' */
llvm_cbe_result:
  llvm_cbe_tmp__266 = (ap_private<512, false> )llvm_cbe_tmp__266__PHI_TEMPORARY;
  llvm_cbe_tmp__267 = (ap_private<512, false> )((ap_private<512, false> )(unsigned int )llvm_cbe_tmp__254&4294967295U);
  llvm_cbe_tmp__268 = (ap_private<512, false> )((ap_private<512, false> )-1ll) << llvm_cbe_tmp__255;
  llvm_cbe_tmp__269 = (ap_private<512, false> )llvm_cbe_tmp__268 ^ ((ap_private<512, false> )-1ll);
  llvm_cbe_tmp__270 = (ap_private<512, false> )llvm_cbe_tmp__268 << llvm_cbe_tmp__267;
  llvm_cbe_tmp__271 = (ap_private<512, false> )(((((unsigned int )llvm_cbe_tmp__254&4294967295U) >= ((unsigned int )512u&4294967295U))) ? ((ap_private<512, false> )((ap_private<512, false> )0u)) : ((ap_private<512, false> )llvm_cbe_tmp__270));
  llvm_cbe_tmp__272 = (ap_private<512, false> )llvm_cbe_tmp__269 | llvm_cbe_tmp__271;
  llvm_cbe_tmp__273 = (ap_private<512, false> )llvm_cbe_tmp__272 & llvm_cbe_Val;
  llvm_cbe_tmp__274 = (ap_private<512, false> )llvm_cbe_tmp__266 << llvm_cbe_tmp__255;
  llvm_cbe_part_set = (ap_private<512, false> )llvm_cbe_tmp__273 | llvm_cbe_tmp__274;
  return llvm_cbe_part_set;
}


ap_private<512, true> llvm_part_select_i512(ap_private<512, true> llvm_cbe_Val, signed int llvm_cbe_Lo, signed int llvm_cbe_High) {
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  ap_private<512, false> llvm_cbe_tmp;
  static  unsigned long long aesl_llvm_cbe_tmp1_count = 0;
  ap_private<512, false> llvm_cbe_tmp1;
  static  unsigned long long aesl_llvm_cbe_less_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_rbits_count = 0;
  ap_private<512, false> llvm_cbe_rbits;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  static  unsigned long long aesl_llvm_cbe_fbits_count = 0;
  ap_private<512, false> llvm_cbe_fbits;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  static  unsigned long long aesl_llvm_cbe_bits_count = 0;
  ap_private<512, false> llvm_cbe_bits;
  ap_private<512, false> llvm_cbe_bits__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_shiftamt_count = 0;
  ap_private<512, false> llvm_cbe_shiftamt;
  ap_private<512, false> llvm_cbe_shiftamt__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_bits2_count = 0;
  ap_private<512, false> llvm_cbe_bits2;
  static  unsigned long long aesl_llvm_cbe_mask_count = 0;
  ap_private<512, false> llvm_cbe_mask;
  static  unsigned long long aesl_llvm_cbe_is_over_shift_count = 0;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  ap_private<512, false> llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_mask3_count = 0;
  ap_private<512, false> llvm_cbe_mask3;
  static  unsigned long long aesl_llvm_cbe_fres_count = 0;
  ap_private<512, false> llvm_cbe_fres;
  static  unsigned long long aesl_llvm_cbe_fres4_count = 0;
  ap_private<512, false> llvm_cbe_fres4;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_count_count = 0;
  ap_private<512, false> llvm_cbe_count;
  ap_private<512, false> llvm_cbe_count__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_val_count = 0;
  ap_private<512, false> llvm_cbe_val;
  ap_private<512, false> llvm_cbe_val__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_rres_count = 0;
  ap_private<512, false> llvm_cbe_rres;
  ap_private<512, false> llvm_cbe_rres__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_decr_count = 0;
  ap_private<512, false> llvm_cbe_decr;
  static  unsigned long long aesl_llvm_cbe_bit_count = 0;
  ap_private<512, false> llvm_cbe_bit;
  static  unsigned long long aesl_llvm_cbe_rshift_count = 0;
  ap_private<512, false> llvm_cbe_rshift;
  static  unsigned long long aesl_llvm_cbe_lshift_count = 0;
  ap_private<512, false> llvm_cbe_lshift;
  static  unsigned long long aesl_llvm_cbe_addbit_count = 0;
  ap_private<512, false> llvm_cbe_addbit;
  static  unsigned long long aesl_llvm_cbe_cond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_part_select_count = 0;
  ap_private<512, false> llvm_cbe_part_select;
  ap_private<512, false> llvm_cbe_part_select__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;

 if (!(llvm_cbe_Lo < 512 && llvm_cbe_High < 512))
   fprintf(stderr, "%s:%d: warning: Part select out of range.\n", __FILE__, __LINE__);
  llvm_cbe_tmp = (ap_private<512, false> )((ap_private<512, false> )(unsigned int )llvm_cbe_High&4294967295U);
  llvm_cbe_tmp1 = (ap_private<512, false> )((ap_private<512, false> )(unsigned int )llvm_cbe_Lo&4294967295U);
  if ((((ap_private<512, false> )llvm_cbe_tmp) < ((ap_private<512, false> )llvm_cbe_tmp1))) {
    goto llvm_cbe_revsize;
  } else {
    goto llvm_cbe_fwdsize;
  }

llvm_cbe_revsize:
  llvm_cbe_rbits = (ap_private<512, false> )((ap_private<512, false> )llvm_cbe_tmp1) - ((ap_private<512, false> )llvm_cbe_tmp);
  llvm_cbe_bits__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_rbits;   /* for PHI node */
  llvm_cbe_shiftamt__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp;   /* for PHI node */
  goto llvm_cbe_compute;

llvm_cbe_fwdsize:
  llvm_cbe_fbits = (ap_private<512, false> )((ap_private<512, false> )llvm_cbe_tmp) - ((ap_private<512, false> )llvm_cbe_tmp1);
  llvm_cbe_bits__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_fbits;   /* for PHI node */
  llvm_cbe_shiftamt__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_tmp1;   /* for PHI node */
  goto llvm_cbe_compute;

llvm_cbe_compute:
  llvm_cbe_bits = (ap_private<512, false> )llvm_cbe_bits__PHI_TEMPORARY;
  llvm_cbe_shiftamt = (ap_private<512, false> )llvm_cbe_shiftamt__PHI_TEMPORARY;
  llvm_cbe_bits2 = (ap_private<512, false> )((ap_private<512, false> )llvm_cbe_bits) + ((ap_private<512, false> )((ap_private<512, false> )1u));
  llvm_cbe_mask = (ap_private<512, false> )((ap_private<512, false> )-1ll) << llvm_cbe_bits2;
  llvm_cbe_tmp__275 = (ap_private<512, false> )(((((ap_private<512, false> )llvm_cbe_bits2) >= ((ap_private<512, false> )((ap_private<512, false> )512u)))) ? ((ap_private<512, false> )((ap_private<512, false> )0u)) : ((ap_private<512, false> )llvm_cbe_mask));
  llvm_cbe_mask3 = (ap_private<512, false> )llvm_cbe_tmp__275 ^ ((ap_private<512, false> )-1ll);
  llvm_cbe_fres = (ap_private<512, false> )((ap_private<512, false> )(((ap_private<512, false> )llvm_cbe_Val) >> ((ap_private<512, false> )llvm_cbe_shiftamt)));
  llvm_cbe_fres4 = (ap_private<512, false> )llvm_cbe_fres & llvm_cbe_mask3;
  if ((((ap_private<512, false> )llvm_cbe_tmp) < ((ap_private<512, false> )llvm_cbe_tmp1))) {
    llvm_cbe_count__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_bits2;   /* for PHI node */
    llvm_cbe_val__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_fres4;   /* for PHI node */
    llvm_cbe_rres__PHI_TEMPORARY = (ap_private<512, false> )((ap_private<512, false> )0u);   /* for PHI node */
    goto llvm_cbe_reverse;
  } else {
    llvm_cbe_part_select__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_fres4;   /* for PHI node */
    goto llvm_cbe_result;
  }

  do {     /* Syntactic loop 'reverse' to make GCC happy */
llvm_cbe_reverse:
  llvm_cbe_count = (ap_private<512, false> )llvm_cbe_count__PHI_TEMPORARY;
  llvm_cbe_val = (ap_private<512, false> )llvm_cbe_val__PHI_TEMPORARY;
  llvm_cbe_rres = (ap_private<512, false> )llvm_cbe_rres__PHI_TEMPORARY;
  llvm_cbe_decr = (ap_private<512, false> )((ap_private<512, false> )llvm_cbe_count) - ((ap_private<512, false> )((ap_private<512, false> )1u));
  llvm_cbe_bit = (ap_private<512, false> )llvm_cbe_val & ((ap_private<512, false> )1u);
  llvm_cbe_rshift = (ap_private<512, false> )((ap_private<512, false> )(((ap_private<512, false> )llvm_cbe_val) >> ((ap_private<512, false> )((ap_private<512, false> )1u))));
  llvm_cbe_lshift = (ap_private<512, false> )llvm_cbe_rres << ((ap_private<512, false> )1u);
  llvm_cbe_addbit = (ap_private<512, false> )llvm_cbe_lshift | llvm_cbe_bit;
  if (((llvm_cbe_decr) == (((ap_private<512, false> )0u)))) {
    llvm_cbe_part_select__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_addbit;   /* for PHI node */
    goto llvm_cbe_result;
  } else {
    llvm_cbe_count__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_decr;   /* for PHI node */
    llvm_cbe_val__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_rshift;   /* for PHI node */
    llvm_cbe_rres__PHI_TEMPORARY = (ap_private<512, false> )llvm_cbe_addbit;   /* for PHI node */
    goto llvm_cbe_reverse;
  }

  } while (1); /* end of syntactic loop 'reverse' */
llvm_cbe_result:
  llvm_cbe_part_select = (ap_private<512, false> )llvm_cbe_part_select__PHI_TEMPORARY;
  return llvm_cbe_part_select;
}

