cmake_minimum_required(VERSION 3.18)
project(API C CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Prepare for files to compile the SEQ targets
file(GLOB_RECURSE CORE "${CMAKE_CURRENT_SOURCE_DIR}/src/core/*.cpp")
file(GLOB_RECURSE SEQ "${CMAKE_CURRENT_SOURCE_DIR}/src/sequential/*.cpp")
file(GLOB_RECURSE EXTERN "${CMAKE_CURRENT_SOURCE_DIR}/src/externlib/*.cpp")
list(FILTER EXTERN EXCLUDE REGEX "hdf5")
# seq
add_library(ops_seq ${CORE} ${EXTERN} ${SEQ} )
target_link_libraries(ops_seq PRIVATE)
install(TARGETS ops_seq DESTINATION lib)
# hdf5_seq
if (HDF5_FOUND)
    add_library(ops_hdf5_seq ${CMAKE_CURRENT_SOURCE_DIR}/src/externlib/ops_hdf5.cpp)
    target_link_libraries(ops_hdf5_seq PRIVATE ${HDF5_LIBRARIES} ${HDF5_HL_LIBRARIES})
    install(TARGETS ops_hdf5_seq DESTINATION lib)
endif ()
# CUDA seq
if (CUDAToolkit_FOUND)
    file(GLOB_RECURSE CUDA "${CMAKE_CURRENT_SOURCE_DIR}/src/cuda/*")
    add_library(ops_cuda ${CORE} ${EXTERN} ${CUDA})
    target_link_libraries(ops_cuda PRIVATE CUDA::cudart_static)
    install(TARGETS ops_cuda DESTINATION lib)
endif ()

if (OpenCL_FOUND)
    file(GLOB_RECURSE OPENCL "${CMAKE_CURRENT_SOURCE_DIR}/src/opencl/*")
    add_library(ops_opencl ${CORE} ${EXTERN} ${OPENCL})
    target_link_libraries(ops_opencl PRIVATE ${OpenCL_LIBRARIES})
    install(TARGETS ops_opencl DESTINATION lib)
endif ()

if (MPI_FOUND)
    file(GLOB_RECURSE MPICORE "${CMAKE_CURRENT_SOURCE_DIR}/src/core/*.cpp")
    list(FILTER MPICORE EXCLUDE REGEX "singlenode")
    file(GLOB_RECURSE MPI "${CMAKE_CURRENT_SOURCE_DIR}/src/mpi/*.cpp")
    list(FILTER MPI EXCLUDE REGEX "opencl")
    list(FILTER MPI EXCLUDE REGEX "cuda")
    list(FILTER MPI EXCLUDE REGEX "hdf5")
    list(FILTER MPI EXCLUDE REGEX "hip")
    # MPI
    add_library(ops_mpi ${MPI} ${MPICORE} ${EXTERN})
    target_link_libraries(ops_mpi PRIVATE MPI::MPI_CXX)
    install(TARGETS ops_mpi DESTINATION lib)
    # HDF5_MPI
    if (HDF5_FOUND)
        add_library(ops_hdf5_mpi ${CMAKE_CURRENT_SOURCE_DIR}/src/mpi/ops_mpi_hdf5.cpp)
        target_link_libraries(ops_hdf5_mpi PRIVATE MPI::MPI_CXX ${HDF5_LIBRARIES} ${HDF5_HL_LIBRARIES})
        install(TARGETS ops_hdf5_mpi DESTINATION lib)
    endif ()
    #MPI_CUDA
    if (CUDAToolkit_FOUND)
        file(GLOB_RECURSE MPICUDA "${CMAKE_CURRENT_SOURCE_DIR}/src/mpi/*")
        list(FILTER MPICUDA EXCLUDE REGEX "opencl")
        list(FILTER MPICUDA EXCLUDE REGEX "host")
        list(FILTER MPICUDA EXCLUDE REGEX "hdf5")
        list(FILTER MPICUDA EXCLUDE REGEX "decl.cpp")
        list(FILTER MPICUDA EXCLUDE REGEX "hip")
        add_library(ops_mpi_cuda ${MPICORE} ${EXTERN} ${MPICUDA}  "${CMAKE_CURRENT_SOURCE_DIR}/src/cuda/ops_cuda_rt_support.cpp")
        target_link_libraries(ops_mpi_cuda PRIVATE CUDA::cudart_static MPI::MPI_CXX)
        install(TARGETS ops_mpi_cuda DESTINATION lib)
    endif ()
    if (OpenCL_FOUND)
        file(GLOB_RECURSE MPIOPENCL "${CMAKE_CURRENT_SOURCE_DIR}/src/mpi/*")
        list(FILTER MPIOPENCL EXCLUDE REGEX "cuda")
        list(FILTER MPIOPENCL EXCLUDE REGEX "host")
        list(FILTER MPIOPENCL EXCLUDE REGEX "hdf5")
        list(FILTER MPIOPENCL EXCLUDE REGEX "decl.cpp")
        list(FILTER MPIOPENCL EXCLUDE REGEX "hip")
        add_library(ops_mpi_opencl ${MPICORE} ${EXTERN} ${MPIOPENCL} "${CMAKE_CURRENT_SOURCE_DIR}/src/opencl/ops_opencl_rt_support.cpp")
        target_link_libraries(ops_mpi_opencl PRIVATE ${OpenCL_LIBRARIES})
        install(TARGETS ops_mpi_opencl DESTINATION lib)
    endif()
endif ()

# Tridiagonal library
if (LIBTRID_PATH)
    # Sequential Tridiagonal Library
    add_library(ops_trid_seq ${CMAKE_CURRENT_SOURCE_DIR}/src/tridiag/ops_tridiag.cpp)
    target_include_directories(ops_trid_seq PRIVATE ${LIBTRID_PATH}/include)
    install(TARGETS ops_trid_seq DESTINATION lib)

    # Sequential CUDA Tridiagonal Library
    if (CUDAToolkit_FOUND)
        add_library(ops_trid_cuda ${CMAKE_CURRENT_SOURCE_DIR}/src/tridiag/ops_tridiag_cuda.cpp)
        target_include_directories(ops_trid_cuda PRIVATE ${LIBTRID_PATH}/include)
        install(TARGETS ops_trid_cuda DESTINATION lib)
    endif ()

    if (MPI_FOUND)
        # MPI Tridiagonal Library
        add_library(ops_trid_mpi ${CMAKE_CURRENT_SOURCE_DIR}/src/tridiag/ops_tridiag_mpi.cpp)
        target_include_directories(ops_trid_mpi PRIVATE ${LIBTRID_PATH}/include)
        install(TARGETS ops_trid_mpi DESTINATION lib)

        if (CUDAToolkit_FOUND)
            # MPI + CUDA Tridiagonal Library
            add_library(ops_trid_mpi_cuda ${CMAKE_CURRENT_SOURCE_DIR}/src/tridiag/ops_tridiag_mpi_cuda.cpp)
            if (NCCL_FOUND)
                target_compile_definitions(ops_trid_mpi_cuda PRIVATE -DTRID_NCCL)
                target_include_directories(ops_trid_mpi_cuda PRIVATE ${NCCL_INCLUDE_DIR})
            endif ()
            target_include_directories(ops_trid_mpi_cuda PRIVATE ${LIBTRID_PATH}/include)
            install(TARGETS ops_trid_mpi_cuda DESTINATION lib)
        endif ()
    endif ()
endif ()
