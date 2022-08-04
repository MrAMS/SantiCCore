include_directories(.)
include_directories(Struct)
include_directories(Algorithm)

add_library(SantiCCore
        SantiMath.c
        SantiError.c
        Struct/SantiMatrix.c
        Struct/SantiPoint.c
        Struct/SantiImage.c
        Struct/SantiRange.c
        Struct/SantiArray.c
        Algorithm/SantiCV.c
        Algorithm/SantiController.c
        )