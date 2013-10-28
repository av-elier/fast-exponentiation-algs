TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg

HEADERS += \
    ../../Include/NTL/ZZXFactoring.h \
    ../../Include/NTL/ZZX.h \
    ../../Include/NTL/ZZVec.h \
    ../../Include/NTL/ZZ_pXFactoring.h \
    ../../Include/NTL/ZZ_pX.h \
    ../../Include/NTL/ZZ_pEXFactoring.h \
    ../../Include/NTL/ZZ_pEX.h \
    ../../Include/NTL/ZZ_pE.h \
    ../../Include/NTL/ZZ_p.h \
    ../../Include/NTL/ZZ.h \
    ../../Include/NTL/xdouble.h \
    ../../Include/NTL/WordVector.h \
    ../../Include/NTL/version.h \
    ../../Include/NTL/vector.h \
    ../../Include/NTL/vec_ZZVec.h \
    ../../Include/NTL/vec_ZZ_pE.h \
    ../../Include/NTL/vec_ZZ_p.h \
    ../../Include/NTL/vec_ZZ.h \
    ../../Include/NTL/vec_xdouble.h \
    ../../Include/NTL/vec_vec_ZZ_pE.h \
    ../../Include/NTL/vec_vec_ZZ_p.h \
    ../../Include/NTL/vec_vec_ZZ.h \
    ../../Include/NTL/vec_vec_ulong.h \
    ../../Include/NTL/vec_vec_RR.h \
    ../../Include/NTL/vec_vec_lzz_pE.h \
    ../../Include/NTL/vec_vec_lzz_p.h \
    ../../Include/NTL/vec_vec_long.h \
    ../../Include/NTL/vec_vec_GF2E.h \
    ../../Include/NTL/vec_vec_GF2.h \
    ../../Include/NTL/vec_ulong.h \
    ../../Include/NTL/vec_RR.h \
    ../../Include/NTL/vec_quad_float.h \
    ../../Include/NTL/vec_lzz_pE.h \
    ../../Include/NTL/vec_lzz_p.h \
    ../../Include/NTL/vec_long.h \
    ../../Include/NTL/vec_GF2XVec.h \
    ../../Include/NTL/vec_GF2E.h \
    ../../Include/NTL/vec_GF2.h \
    ../../Include/NTL/vec_double.h \
    ../../Include/NTL/tools.h \
    ../../Include/NTL/SPMM_ASM.h \
    ../../Include/NTL/RR.h \
    ../../Include/NTL/quad_float.h \
    ../../Include/NTL/pair_ZZX_long.h \
    ../../Include/NTL/pair_ZZ_pX_long.h \
    ../../Include/NTL/pair_ZZ_pEX_long.h \
    ../../Include/NTL/pair_lzz_pX_long.h \
    ../../Include/NTL/pair_lzz_pEX_long.h \
    ../../Include/NTL/pair_GF2X_long.h \
    ../../Include/NTL/pair_GF2EX_long.h \
    ../../Include/NTL/pair.h \
    ../../Include/NTL/new.h \
    ../../Include/NTL/matrix.h \
    ../../Include/NTL/mat_ZZ_pE.h \
    ../../Include/NTL/mat_ZZ_p.h \
    ../../Include/NTL/mat_ZZ.h \
    ../../Include/NTL/mat_RR.h \
    ../../Include/NTL/mat_poly_ZZ_p.h \
    ../../Include/NTL/mat_poly_ZZ.h \
    ../../Include/NTL/mat_poly_lzz_p.h \
    ../../Include/NTL/mat_lzz_pE.h \
    ../../Include/NTL/mat_lzz_p.h \
    ../../Include/NTL/mat_GF2E.h \
    ../../Include/NTL/mat_GF2.h \
    ../../Include/NTL/mach_desc.h \
    ../../Include/NTL/lzz_pXFactoring.h \
    ../../Include/NTL/lzz_pX.h \
    ../../Include/NTL/lzz_pEXFactoring.h \
    ../../Include/NTL/lzz_pEX.h \
    ../../Include/NTL/lzz_pE.h \
    ../../Include/NTL/lzz_p.h \
    ../../Include/NTL/LLL.h \
    ../../Include/NTL/lip.h \
    ../../Include/NTL/HNF.h \
    ../../Include/NTL/GF2XVec.h \
    ../../Include/NTL/GF2XFactoring.h \
    ../../Include/NTL/GF2X.h \
    ../../Include/NTL/GF2EXFactoring.h \
    ../../Include/NTL/GF2EX.h \
    ../../Include/NTL/GF2E.h \
    ../../Include/NTL/GF2.h \
    ../../Include/NTL/g_lip.h \
    ../../Include/NTL/fileio.h \
    ../../Include/NTL/FFT.h \
    ../../Include/NTL/FacVec.h \
    ../../Include/NTL/def_config.h \
    ../../Include/NTL/ctools.h \
    ../../Include/NTL/config.h \
    ../../Include/NTL/c_lip.h
