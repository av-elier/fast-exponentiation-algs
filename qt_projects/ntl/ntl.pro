TEMPLATE = lib
#CONFIG += console
CONFIG+= staticlib
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:\university\Information_security_methods\fast-exponention-algs\include"

QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter

SOURCES += \
    ../../src/ntl/ZZXFactoring.cpp \
    ../../src/ntl/ZZXCharPoly.cpp \
    ../../src/ntl/ZZX1.cpp \
    ../../src/ntl/ZZX.cpp \
    ../../src/ntl/ZZVec.cpp \
    ../../src/ntl/ZZ_pXFactoring.cpp \
    ../../src/ntl/ZZ_pXCharPoly.cpp \
    ../../src/ntl/ZZ_pX1.cpp \
    ../../src/ntl/ZZ_pX.cpp \
    ../../src/ntl/ZZ_pEXFactoring.cpp \
    ../../src/ntl/ZZ_pEX.cpp \
    ../../src/ntl/ZZ_pE.cpp \
    ../../src/ntl/ZZ_p.cpp \
    ../../src/ntl/ZZ.cpp \
    ../../src/ntl/xdouble.cpp \
    ../../src/ntl/WordVector.cpp \
    ../../src/ntl/vec_ZZ_pE.cpp \
    ../../src/ntl/vec_ZZ_p.cpp \
    ../../src/ntl/vec_ZZ.cpp \
    ../../src/ntl/vec_RR.cpp \
    ../../src/ntl/vec_lzz_pE.cpp \
    ../../src/ntl/vec_lzz_p.cpp \
    ../../src/ntl/vec_GF2E.cpp \
    ../../src/ntl/vec_GF2.cpp \
    ../../src/ntl/tools.cpp \
    ../../src/ntl/RR.cpp \
    ../../src/ntl/quad_float.cpp \
    ../../src/ntl/mat_ZZ_pE.cpp \
    ../../src/ntl/mat_ZZ_p.cpp \
    ../../src/ntl/mat_ZZ.cpp \
    ../../src/ntl/mat_RR.cpp \
    ../../src/ntl/mat_poly_ZZ_p.cpp \
    ../../src/ntl/mat_poly_ZZ.cpp \
    ../../src/ntl/mat_poly_lzz_p.cpp \
    ../../src/ntl/mat_lzz_pE.cpp \
    ../../src/ntl/mat_lzz_p.cpp \
    ../../src/ntl/mat_GF2E.cpp \
    ../../src/ntl/mat_GF2.cpp \
    ../../src/ntl/lzz_pXFactoring.cpp \
    ../../src/ntl/lzz_pXCharPoly.cpp \
    ../../src/ntl/lzz_pX1.cpp \
    ../../src/ntl/lzz_pX.cpp \
    ../../src/ntl/lzz_pEXFactoring.cpp \
    ../../src/ntl/lzz_pEX.cpp \
    ../../src/ntl/lzz_pE.cpp \
    ../../src/ntl/lzz_p.cpp \
    ../../src/ntl/LLL_XD.cpp \
    ../../src/ntl/LLL_RR.cpp \
    ../../src/ntl/LLL_QP.cpp \
    ../../src/ntl/LLL_FP.cpp \
    ../../src/ntl/LLL.cpp \
    ../../src/ntl/lip.cpp \
    ../../src/ntl/HNF.cpp \
    ../../src/ntl/GF2XVec.cpp \
    ../../src/ntl/GF2XFactoring.cpp \
    ../../src/ntl/GF2X1.cpp \
    ../../src/ntl/GF2X.cpp \
    ../../src/ntl/GF2EXFactoring.cpp \
    ../../src/ntl/GF2EX.cpp \
    ../../src/ntl/GF2E.cpp \
    ../../src/ntl/GF2.cpp \
    ../../src/ntl/GetTime.cpp \
    ../../src/ntl/G_LLL_XD.cpp \
    ../../src/ntl/G_LLL_RR.cpp \
    ../../src/ntl/G_LLL_QP.cpp \
    ../../src/ntl/G_LLL_FP.cpp \
    ../../src/ntl/fileio.cpp \
    ../../src/ntl/FFT.cpp \
    ../../src/ntl/FacVec.cpp \
    ../../src/ntl/ctools.cpp

QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg

HEADERS += \
    ../../include/NTL/ZZXFactoring.h \
    ../../include/NTL/ZZX.h \
    ../../include/NTL/ZZVec.h \
    ../../include/NTL/ZZ_pXFactoring.h \
    ../../include/NTL/ZZ_pX.h \
    ../../include/NTL/ZZ_pEXFactoring.h \
    ../../include/NTL/ZZ_pEX.h \
    ../../include/NTL/ZZ_pE.h \
    ../../include/NTL/ZZ_p.h \
    ../../include/NTL/ZZ.h \
    ../../include/NTL/xdouble.h \
    ../../include/NTL/WordVector.h \
    ../../include/NTL/version.h \
    ../../include/NTL/vector.h \
    ../../include/NTL/vec_ZZVec.h \
    ../../include/NTL/vec_ZZ_pE.h \
    ../../include/NTL/vec_ZZ_p.h \
    ../../include/NTL/vec_ZZ.h \
    ../../include/NTL/vec_xdouble.h \
    ../../include/NTL/vec_vec_ZZ_pE.h \
    ../../include/NTL/vec_vec_ZZ_p.h \
    ../../include/NTL/vec_vec_ZZ.h \
    ../../include/NTL/vec_vec_ulong.h \
    ../../include/NTL/vec_vec_RR.h \
    ../../include/NTL/vec_vec_lzz_pE.h \
    ../../include/NTL/vec_vec_lzz_p.h \
    ../../include/NTL/vec_vec_long.h \
    ../../include/NTL/vec_vec_GF2E.h \
    ../../include/NTL/vec_vec_GF2.h \
    ../../include/NTL/vec_ulong.h \
    ../../include/NTL/vec_RR.h \
    ../../include/NTL/vec_quad_float.h \
    ../../include/NTL/vec_lzz_pE.h \
    ../../include/NTL/vec_lzz_p.h \
    ../../include/NTL/vec_long.h \
    ../../include/NTL/vec_GF2XVec.h \
    ../../include/NTL/vec_GF2E.h \
    ../../include/NTL/vec_GF2.h \
    ../../include/NTL/vec_double.h \
    ../../include/NTL/tools.h \
    ../../include/NTL/SPMM_ASM.h \
    ../../include/NTL/RR.h \
    ../../include/NTL/quad_float.h \
    ../../include/NTL/pair_ZZX_long.h \
    ../../include/NTL/pair_ZZ_pX_long.h \
    ../../include/NTL/pair_ZZ_pEX_long.h \
    ../../include/NTL/pair_lzz_pX_long.h \
    ../../include/NTL/pair_lzz_pEX_long.h \
    ../../include/NTL/pair_GF2X_long.h \
    ../../include/NTL/pair_GF2EX_long.h \
    ../../include/NTL/pair.h \
    ../../include/NTL/new.h \
    ../../include/NTL/matrix.h \
    ../../include/NTL/mat_ZZ_pE.h \
    ../../include/NTL/mat_ZZ_p.h \
    ../../include/NTL/mat_ZZ.h \
    ../../include/NTL/mat_RR.h \
    ../../include/NTL/mat_poly_ZZ_p.h \
    ../../include/NTL/mat_poly_ZZ.h \
    ../../include/NTL/mat_poly_lzz_p.h \
    ../../include/NTL/mat_lzz_pE.h \
    ../../include/NTL/mat_lzz_p.h \
    ../../include/NTL/mat_GF2E.h \
    ../../include/NTL/mat_GF2.h \
    ../../include/NTL/mach_desc.h \
    ../../include/NTL/lzz_pXFactoring.h \
    ../../include/NTL/lzz_pX.h \
    ../../include/NTL/lzz_pEXFactoring.h \
    ../../include/NTL/lzz_pEX.h \
    ../../include/NTL/lzz_pE.h \
    ../../include/NTL/lzz_p.h \
    ../../include/NTL/LLL.h \
    ../../include/NTL/lip.h \
    ../../include/NTL/HNF.h \
    ../../include/NTL/GF2XVec.h \
    ../../include/NTL/GF2XFactoring.h \
    ../../include/NTL/GF2X.h \
    ../../include/NTL/GF2EXFactoring.h \
    ../../include/NTL/GF2EX.h \
    ../../include/NTL/GF2E.h \
    ../../include/NTL/GF2.h \
    ../../include/NTL/g_lip.h \
    ../../include/NTL/fileio.h \
    ../../include/NTL/FFT.h \
    ../../include/NTL/FacVec.h \
    ../../include/NTL/def_config.h \
    ../../include/NTL/ctools.h \
    ../../include/NTL/config.h \
    ../../include/NTL/c_lip.h
