//
// <copyright file="NoGPU.cpp" company="Microsoft">
//     Copyright (c) Microsoft Corporation.  All rights reserved.
// </copyright>
//

#include "stdafx.h"

#ifdef CPUONLY

#include "GPUMatrix.h"
#include "GPUSparseMatrix.h"

#pragma warning (disable: 4100) // unreferenced formal parameter, which is OK since all functions in here are dummies; disabling this allows to copy-paste prototypes here when we add new functions

namespace Microsoft { namespace MSR { namespace CNTK {
    void PrepareDevice(short deviceId);

#pragma region Constructors and Destructor

    template<class ElemType> GPUSparseMatrix<ElemType>::GPUSparseMatrix() { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::ZeroInit() { }

    template<class ElemType> GPUSparseMatrix<ElemType>::GPUSparseMatrix(const GPUMatrix<ElemType>& deepCopy) { }


    template<class ElemType> GPUSparseMatrix<ElemType>::GPUSparseMatrix(const GPUSparseMatrix<ElemType>& deepCopy) { }

    template<class ElemType> GPUSparseMatrix<ElemType>::GPUSparseMatrix(const size_t numRows, const size_t numCols, const size_t nz, ElemType* pArray, 
        const size_t matrixFlags /*=matrixFormatSparseCSR*/, int deviceId /*=MANAGEDEXTERN*/, const size_t elemSizeAllocated /*=0*/) { }

    // PrepareDevice - Setup the correct cuda context for an operation
    // deviceId - the device on which the operation will take place
    //            defaults to -1, which means use matrices current device
    template<class ElemType> void GPUSparseMatrix<ElemType>::PrepareDevice(short deviceId /*=-1*/) const
    {}

    template<class ElemType> void GPUSparseMatrix<ElemType>::DeepCopy(const GPUSparseMatrix<ElemType>& deepCopy) { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::SetValue(const GPUSparseMatrix<ElemType>& deepCopy) { }

    template<class ElemType> GPUMatrix<ElemType> GPUSparseMatrix<ElemType>::CopyToDenseMatrix()
    {
        GPUMatrix<ElemType> res;
        return res;            
    }

    template<class ElemType> void GPUSparseMatrix<ElemType>::SetValue(const GPUMatrix<ElemType>& denseMatrix) { }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::operator=(const GPUSparseMatrix<ElemType>& deepCopy) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>::GPUSparseMatrix(GPUSparseMatrix<ElemType>&& moveFrom) { }
    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::operator=(GPUSparseMatrix<ElemType>&& moveFrom) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>::~GPUSparseMatrix() { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::ClearNew() { }
    template<class ElemType> void GPUSparseMatrix<ElemType>::Clear() { }

    //ResizeAs - Resize this sparse matrix to have the same element structure as the passed matrix
    // a - sparse matrix whose structure we want to clone
    // remark: this was done for element wise operations where the structure will be identical after an operation
    template<class ElemType> void GPUSparseMatrix<ElemType>::ResizeAs(const GPUSparseMatrix<ElemType>& a) { }

    //-------------------------------------------------------------------------
    // Start of new GPU Sparse Matrix code 
    //-------------------------------------------------------------------------

    template<class ElemType> void GPUSparseMatrix<ElemType>::Init() { }
    template<class ElemType> GPUSparseMatrix<ElemType>::GPUSparseMatrix(const MatrixFormat format, const int deviceId) { }

    template<class ElemType> ElemType* GPUSparseMatrix<ElemType>::BufferPointer() const
    {
        return this->m_blockVal;
    }

    template<class ElemType> void GPUSparseMatrix<ElemType>::Resize(const size_t numRows, const size_t numCols, size_t size) { }

    //Reset matrix so it can be reused
    template<class ElemType> void GPUSparseMatrix<ElemType>::Reset() { }

#pragma endregion Constructors and Destructor

#pragma region Static BLAS Functions
    
    // copy features to GPU matrix 
    template<class ElemType> void GPUSparseMatrix<ElemType>::SetMatrixFromCSCFormat(size_t *h_row, size_t *h_rowIdx, size_t size, size_t blockSize) { }
       
    template<class ElemType> void GPUSparseMatrix<ElemType>::SetMatrixFromLabelAndClass(size_t *h_row, size_t *h_block2Id, size_t *h_block2UniqId, size_t labelSize, size_t expandedSize, size_t blockSize) { }

    // forward pass from feature to hidden layer
    template<class ElemType> void GPUSparseMatrix<ElemType>::MultiplyAndWeightedAdd(ElemType alpha, const GPUMatrix<ElemType>& lhs, const bool transposeA, 
        const GPUSparseMatrix<ElemType>& rhs, const bool transposeB, ElemType beta, GPUMatrix<ElemType>& c) { }

    // backward pass from hidden layer to feature weight
    template<class ElemType> void GPUSparseMatrix<ElemType>::MultiplyAndAdd(ElemType alpha, const GPUMatrix<ElemType>& lhs, const bool transposeA, 
        const GPUSparseMatrix<ElemType>& rhs, const bool transposeB, GPUSparseMatrix<ElemType>& c) { }

    // used for gradients udpate
    template<class ElemType> void GPUSparseMatrix<ElemType>::ScaleAndAdd(const ElemType alpha, const GPUSparseMatrix<ElemType>& lhs, GPUMatrix<ElemType>& rhs) { }

    // a: H x No: H is hidden layer size and No is mini-batch size
    // weight: V x H, V is vocab size
    // label: V x No
    // cls: 2 x Nc, Nc is number of classes, each col is start and end word ids of a class
    // idx2cls: V x 1, mapping from word to class id
    // etp: V x No, stores predicted values
    template<class ElemType> void GPUSparseMatrix<ElemType>::ClassEntropy(const GPUMatrix<ElemType>& a, const GPUMatrix<ElemType>& weight,
        const GPUSparseMatrix<ElemType> & label, const GPUMatrix<ElemType>& cls, 
        const GPUMatrix<ElemType>& idx2cls, GPUSparseMatrix<ElemType>& etp, GPUMatrix<ElemType>& entropyScore) { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::ClassEntropyError(GPUSparseMatrix<ElemType>& a) { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::ClassEntropyGradientOfInput(const GPUSparseMatrix<ElemType>& error, const GPUMatrix<ElemType>& weight,  GPUMatrix<ElemType>& grd) { }
    
    template<class ElemType> void GPUSparseMatrix<ElemType>::ClassEntropyGradientOfWeight(const GPUSparseMatrix<ElemType>& error,  const GPUMatrix<ElemType>& input, const GPUSparseMatrix<ElemType> & label, const GPUMatrix<ElemType>& cls, 
        const GPUMatrix<ElemType>& idx2cls, GPUSparseMatrix<ElemType>& grd) { }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceTruncate (const ElemType threshold) { return *this; } 

    // normal update for smoothed gradients c and current gradients (this)
    template<class ElemType> 
    void GPUSparseMatrix<ElemType>::NormalGrad(GPUMatrix<ElemType>& c, const ElemType momentum) { }

    //-------------------------------------------------------------------------
    // End of new GPU Sparse Matrix code 
    //-------------------------------------------------------------------------

    template<class ElemType> void  GPUSparseMatrix<ElemType>::MultiplyAndWeightedAdd(ElemType alpha, const GPUSparseMatrix<ElemType>& a, const bool transposeA, 
        const GPUMatrix<ElemType>& /*b*/, ElemType beta, GPUMatrix<ElemType>& c) { }
    template<class ElemType> void GPUSparseMatrix<ElemType>::Multiply(const GPUSparseMatrix<ElemType>& S, const GPUMatrix<ElemType>& D, GPUMatrix<ElemType>& C) { }
    template<class ElemType> void GPUSparseMatrix<ElemType>::Multiply(const GPUMatrix<ElemType>& D, const GPUSparseMatrix<ElemType>& S, GPUMatrix<ElemType>& C) { }

    // ElemCountFromBufferSize - Return the elemCountAllocated for a particular buffersize
    // totalBufferSize - total buffer we have to use
    // return: size of allocated elements/index slots available
    template<class ElemType> size_t GPUSparseMatrix<ElemType>::ElemCountFromBufferSize(size_t totalBufferSize)
    {
        return 0;
    }

    // PrepareBuffer - Get the dimensions start buffer, computes the starting row/column of each value
    // m - rows in the source
    // n - cols in the source
    // canReuseBuffer - target matrix can be reused for temporary space
    // func - function to call to count elements in the result (returns count, and fills csrRowPtr array)
    template<class ElemType>
    void GPUSparseMatrix<ElemType>::PrepareBuffer(size_t m, size_t n, bool canReuseBuffer, std::function<size_t (int* csrRowPtrC)> func) { }

    // Multiply - multiply one spares matrix by another sparse matrix
    // S1 - first sparse matrix
    // transposeS1 - transpose first matrix?
    // S2 - second sparse matrix
    // transposeS2 - tanspose second matrix?
    // c - result matrix
    // NOTE: if c has enough space allocated, it will be reused, otherwise it will be freed and a new memory block used
    template<class ElemType> void GPUSparseMatrix<ElemType>::Multiply(const GPUSparseMatrix<ElemType>& S1, bool transposeS1, const GPUSparseMatrix<ElemType>& S2, bool transposeS2, GPUSparseMatrix<ElemType> &c) { }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignProductOf(const GPUSparseMatrix<ElemType>& a, const bool transposeA, const GPUSparseMatrix<ElemType>& /*b*/, const bool transposeB) { return *this; }

    template<class ElemType> void GPUSparseMatrix<ElemType>::ScaleAndAdd(ElemType alpha,const GPUSparseMatrix<ElemType>& a, ElemType beta, const GPUSparseMatrix<ElemType>& /*b*/, GPUSparseMatrix<ElemType>& c) { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::ScaleAndAdd(ElemType alpha,const GPUSparseMatrix<ElemType>& a, ElemType beta, const GPUMatrix<ElemType>& /*b*/, GPUMatrix<ElemType>& c) { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::ScaleAndAdd(ElemType alpha,const GPUMatrix<ElemType>& /*a*/, ElemType beta, const GPUSparseMatrix<ElemType>& /*b*/, GPUMatrix<ElemType>& c) { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::Scale(ElemType alpha, GPUSparseMatrix<ElemType>& a) { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::ElementWisePower (ElemType alpha, const GPUSparseMatrix<ElemType>& a, GPUSparseMatrix<ElemType>& c) { }

    template<class ElemType> ElemType GPUSparseMatrix<ElemType>::InnerProductOfMatrices(const GPUSparseMatrix<ElemType>& a, const GPUMatrix<ElemType>& /*b*/)
    {
        return ElemType(0);        
    }

    template<class ElemType> ElemType GPUSparseMatrix<ElemType>::InnerProductOfMatrices(const GPUMatrix<ElemType>& /*a*/, const GPUSparseMatrix<ElemType>& /*b*/)
    {
        return ElemType(0);        
    }

    template<class ElemType> bool GPUSparseMatrix<ElemType>::AreEqual(const GPUSparseMatrix<ElemType>& a, const GPUSparseMatrix<ElemType>& /*b*/, 
        const ElemType threshold)
    {
        return false;
    }

    template<class ElemType> bool GPUSparseMatrix<ElemType>::AreEqual(const GPUMatrix<ElemType>& /*a*/, const GPUSparseMatrix<ElemType>& /*b*/, 
        const ElemType threshold)
    {
            return false;
    }

    template<class ElemType> bool GPUSparseMatrix<ElemType>::AreEqual(const GPUSparseMatrix<ElemType>& a, const GPUMatrix<ElemType>& /*b*/, 
        const ElemType threshold)
    {
            return false;
    }

    template<class ElemType> bool GPUSparseMatrix<ElemType>::IsEqualTo(const GPUSparseMatrix<ElemType>& a, const ElemType threshold) const
    {
        return false;
    }

    template<class ElemType> bool GPUSparseMatrix<ElemType>::IsEqualTo(const GPUMatrix<ElemType>& /*a*/, const ElemType threshold) const
    {
        return false;
    }
#pragma endregion Static BLAS Functions

#pragma region Member BLAS Functions

    template<class ElemType> int GPUSparseMatrix<ElemType>::GetComputeDeviceId() const 
    {
        return -1;
    }

    template<class ElemType> GPUMatrix<ElemType> GPUSparseMatrix<ElemType>::ElementProductOf (const GPUSparseMatrix<ElemType>& a, const GPUMatrix<ElemType>& /*b*/)
    {
        GPUMatrix<ElemType> c;
        return c;
    }

    template<class ElemType> GPUMatrix<ElemType> GPUSparseMatrix<ElemType>::ElementProductOf (const GPUMatrix<ElemType>& a, const GPUSparseMatrix<ElemType>& b)
    {
        return GPUSparseMatrix<ElemType>::ElementProductOf(b,a);        
    }

    template<class ElemType> GPUSparseMatrix<ElemType> GPUSparseMatrix<ElemType>::operator+ (const GPUSparseMatrix<ElemType>& a) const { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType> GPUSparseMatrix<ElemType>::operator- (const GPUSparseMatrix<ElemType>& a) const { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::operator^=(ElemType alpha) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType> GPUSparseMatrix<ElemType>::operator^ (ElemType alpha) const { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::operator*=(ElemType alpha) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType> GPUSparseMatrix<ElemType>::operator* (ElemType alpha) const { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignElementPowerOf(const GPUSparseMatrix<ElemType>& a, const ElemType power) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType> GPUSparseMatrix<ElemType>::Transpose() const { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignTransposeOf(const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> void GPUSparseMatrix<ElemType>::InplaceTranspose() { }

    template<class ElemType> ElemType GPUSparseMatrix<ElemType>::SumOfAbsElements() const
    {
        return ElemType(0);
    }

    template<class ElemType> ElemType GPUSparseMatrix<ElemType>::SumOfElements() const
    {
        return ElemType(0);
    }


    template<class ElemType> ElemType GPUSparseMatrix<ElemType>::FrobeniusNorm() const 
    {
        return ElemType(0);
    }

    template<class ElemType> ElemType GPUSparseMatrix<ElemType>::MatrixNormInf() const
    {
        return ElemType(0);
    }

    template<class ElemType> ElemType GPUSparseMatrix<ElemType>::MatrixNorm1() const
    {
        return ElemType(0);
    }

#pragma endregion Member BLAS Functions

#pragma region Other Functions

    template<class ElemType>    
    GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::ElementInverse () { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignElementInverseOf (const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceSigmoid() { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignSigmoidOf (const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceLinearRectifierDerivative() { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignLinearRectifierDerivativeOf (const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceTanh() { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignTanhOf (const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceSqrt() { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignSqrtOf (const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceExp() { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignExpOf (const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceLog() { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignLogOf (const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceAbs() { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignAbsOf (const GPUSparseMatrix<ElemType>& a) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceTruncateBottom (const ElemType threshold) { return *this; }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignTruncateBottomOf (const GPUSparseMatrix<ElemType>& a, const ElemType threshold) { return *this; }   

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::InplaceTruncateTop (const ElemType threshold)
    {
        return *this;        
    }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::AssignTruncateTopOf (const GPUSparseMatrix<ElemType>& a, const ElemType threshold)
    {
        return *this;        
    }

    template<class ElemType> GPUSparseMatrix<ElemType>& GPUSparseMatrix<ElemType>::SetToZeroIfAbsLessThan (const ElemType threshold)
    {
        return *this;  
    }
    template<class ElemType> void GPUSparseMatrix<ElemType>::Unrolling (//GPUSparseMatrix<ElemType>& debugMatrix, 
        GPUMatrix<ElemType>& UnrolledMatrix, const GPUMatrix<ElemType>& InMatrix, GPUSparseMatrix<ElemType>& UnrollMapping, 
        const int inputWidth, const int inputHeight, const int inputChannelNum,
        const int FltWidth,const int FltHeight, const int FltChannel,
        const int FltStepW,  const int FltStepH)
    {
    }

#pragma endregion

#pragma region Helper Functions

    template<class ElemType> void GPUSparseMatrix<ElemType>::performInplaceFunction(int kind) { }

    template<class ElemType> void GPUSparseMatrix<ElemType>::SetMatrixFromCSRFormat(int *h_CSRRow, int *h_Col, ElemType *h_Val, size_t nz, size_t numRows, size_t numCols, bool IsOnDevice, int devId) { }

    // NOTE: we should change this to just use a single buffer, and return pointers into it
    template<class ElemType> void GPUSparseMatrix<ElemType>::GetMatrixFromCSRFormat(int*& h_CSRRow, int*& h_Col, ElemType*& h_Val, size_t &nz, size_t &numRows, size_t &numCols) const
    {}

#pragma endregion Helper Functions

    template class GPUSparseMatrix<float>; 
    template class GPUSparseMatrix<double>;    

    template <class ElemType>
    MATH_API File& operator>>(File& stream, GPUSparseMatrix<ElemType>& us)
    {
        return stream;
    }

    template MATH_API File& operator>>(File& stream, GPUSparseMatrix<float>& us);
    template MATH_API File& operator>>(File& stream, GPUSparseMatrix<double>& us);

    template <class ElemType>
    MATH_API File& operator<<(File& stream, const GPUSparseMatrix<ElemType>& us)
    {
        return stream;
    }
    template MATH_API File& operator<<(File& stream, const GPUSparseMatrix<float>& us);
    template MATH_API File& operator<<(File& stream, const GPUSparseMatrix<double>& us);


#pragma region DeviceBoundNumber class

    template<class ElemType> DeviceBoundNumber<ElemType>::DeviceBoundNumber(const DeviceBoundNumber<ElemType> &deepCopy)
    {
        NOT_IMPLEMENTED;
    }

    template<class ElemType> DeviceBoundNumber<ElemType>::DeviceBoundNumber(DeviceBoundNumber<ElemType> &&shallowCopy)
    {
        this->ShallowCopyFrom(shallowCopy.m_data,shallowCopy.m_computeDevice);
        shallowCopy.m_data=NULL;
    }

    template<class ElemType> void DeviceBoundNumber<ElemType>::ShallowCopyFrom(ElemType* newVal,int newValsDevceId) { }

    template<class ElemType> DeviceBoundNumber<ElemType>::~DeviceBoundNumber() { }

#pragma endregion DeviceBoundNumber class

#pragma region Helper functions

    // GetBestGPUDeviceId - Get the best GPU DeviceId, based on cuda information
    //  TODO: should be replaced by BestGpu class instead, it's much better
    template<class ElemType> int GPUMatrix<ElemType>::GetBestGPUDeviceId() //returns -1 if no GPUs can be used
    {      
        return -1; // CPU
    }

    // PrepareDevice - Setup the correct cuda context for an operation
    // deviceId - the device on which the operation will take place
    //            defaults to -1, which means use matrices current device
    template<class ElemType> void GPUMatrix<ElemType>::PrepareDevice(short deviceId /*=-1*/) const
    {}

    template<class ElemType> ElemType* GPUMatrix<ElemType>::CopyToArray() const
    {
        return NULL;
    }

    //memory will be allocated by the callee if not enough but need to be deleted by the caller after it's done
    //return number of elements copied
    template<class ElemType> size_t  GPUMatrix<ElemType>::CopyToArray(ElemType*& arrayCopyTo, size_t& currentArraySize) const
    {
        return 0;
    }

    template<class ElemType> void GPUMatrix<ElemType>::ChangeDeviceTo(int to_id) { }

    template<class ElemType> void GPUMatrix<ElemType>::performInplaceFunction(int kind)    
    {}


#pragma endregion Helper functions

#pragma region Constructors and Destructor

   //should only be used by constructors.
    template<class ElemType> void GPUMatrix<ElemType>::ZeroInit(int deviceId) { }

    template<class ElemType> GPUMatrix<ElemType>::GPUMatrix(int deviceId) 
    {};

    //matrixName is used to verify that correct matrix is read.
    template<class ElemType> GPUMatrix<ElemType>::GPUMatrix(FILE* f, const char * matrixName, int deviceId) { }

    template<class ElemType> GPUMatrix<ElemType>::GPUMatrix(const size_t numRows, const size_t numCols,int deviceId) { };

    template<class ElemType> GPUMatrix<ElemType>::GPUMatrix(const size_t numRows, const size_t numCols, ElemType *pArray, const size_t matrixFlags, int deviceId) { };               

    template<class ElemType> GPUMatrix<ElemType>::GPUMatrix(const GPUMatrix<ElemType>& deepCopyFrom) { }

    template<class ElemType> GPUMatrix<ElemType>::GPUMatrix(GPUMatrix<ElemType>&& moveFrom) { }

    //assignment operator, deep copy
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator=(const GPUMatrix<ElemType>& deepCopyFrom)   { return *this; }

    //move assignment operator, shallow copy
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator=(GPUMatrix<ElemType>&& moveFrom)   { return *this; }

    template<class ElemType> GPUMatrix<ElemType>::~GPUMatrix(void) { }

    template<class ElemType> void GPUMatrix<ElemType>::Clear() { }
#pragma endregion Constructors and Destructor 

    template<class ElemType> int GPUMatrix<ElemType>::GetComputeDeviceId() const 
    {
        return -1;
    }

#pragma region Basic Operators
    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::ColumnSlice(size_t startColumn, size_t numCols) const
    {
        GPUMatrix<ElemType> slice;

        return slice;
    }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignColumnSlice(const GPUMatrix<ElemType>& fromMatrix, size_t startColumn, size_t numCols) { return *this; }     


    //for each column of a, we assign numRows starting from startIndex to this
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignRowSliceValuesOf(const GPUMatrix<ElemType>& /*a*/, const size_t startIndex, const size_t numRows) { return *this; }

    //for each column of a, we add all rows of a to this starting from startIndex
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AddToRowSliceValuesOf(const GPUMatrix<ElemType>& /*a*/, const size_t startIndex, const size_t numRows) { return *this; }
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AddWithRowSliceValuesOf(const GPUMatrix<ElemType>& /*a*/, const size_t startIndex, const size_t numRows) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignRepeatOf(const GPUMatrix<ElemType>& /*a*/, const size_t numRowRepeats, const size_t numColRepeats) { return *this; }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::Transpose() const { return *this; }

    // GetCublasHandle - get a cublas handle for the given GPU, should only need one per GPU
    // computeDevice - The compute device for which the cublas handle is desired
    // returns: cublas handle
    // NOTE: we currently don't bother to ever free the CUBLAS handle, it will be freed automatically by CUDA when the process ends
    template<class ElemType> cublasHandle_t GPUMatrix<ElemType>::GetCublasHandle(int computeDevice/*=-1*/)
    {
        cublasHandle_t cuHandle = 0;
        return cuHandle;
    }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignTransposeOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> void GPUMatrix<ElemType>::SetValue(const ElemType v) { }

    template<class ElemType> void GPUMatrix<ElemType>::SetValue(const ElemType* d_v) //d_v is pointer to the the value in GPU memory
    {}

    template<class ElemType> void GPUMatrix<ElemType>::SetColumn(const ElemType* colPointer, size_t colInd) { }

    template<class ElemType> void GPUMatrix<ElemType>::SetValue(const GPUMatrix<ElemType>& deepCopyFrom) { }

    template<class ElemType>    
    void GPUMatrix<ElemType>::SetValue(const size_t numRows, const size_t numCols, ElemType *pArray, size_t matrixFlags, int deviceId) { }


    template<class ElemType> void GPUMatrix<ElemType>::SetDiagonalValue(const ElemType v) { }

    template<class ElemType> void GPUMatrix<ElemType>::SetDiagonalValue(GPUMatrix<ElemType>& vector) { }

    template<class ElemType> void GPUMatrix<ElemType>::SetUniformRandomValue(const ElemType low, const ElemType high, unsigned long seed) { }

    template<class ElemType> void GPUMatrix<ElemType>::SetGaussianRandomValue(const ElemType mean, const ElemType sigma, unsigned long seed) { }

    //maskRate: percentage of values masked out (similar to dropout rate)
    //scaleValue: which scale value to set to the left ones (unmasked items).
    template<class ElemType> void GPUMatrix<ElemType>::SetUniformRandomMask(const ElemType maskRate, const ElemType scaleValue, unsigned long seed) { }

    template<class ElemType> void GPUMatrix<ElemType>::Adagrad(GPUMatrix<ElemType>& gradients) { }

    template<class ElemType> void GPUMatrix<ElemType>::RmsProp(GPUMatrix<ElemType>& gradients, ElemType RMS_GAMMA, ElemType RMS_WGT_INC, ElemType RMS_WGT_MAX, ElemType RMS_WGT_DEC, ElemType RMS_WGT_MIN) { }

    template<class ElemType> void GPUMatrix<ElemType>::Reshape(const size_t numRows, const size_t numCols) { }

    template<class ElemType> void GPUMatrix<ElemType>::Resize(const size_t numRows, const size_t numCols, bool growOnly) { }

    template<class ElemType> size_t GPUMatrix<ElemType>::LocateElement (const size_t row, const size_t col) const 
    { 
        return 0;
    }  

    template<class ElemType> size_t GPUMatrix<ElemType>::LocateColumn (const size_t col) const 
    { 
        return 0;
    }  

    template<class ElemType> ElemType GPUMatrix<ElemType>::Get00Element() const 
    {        
        ElemType res=0;        
        return res;
    }
#pragma endregion Basic Operators

#pragma region Member BLAS Functions
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator+= (ElemType alpha)  { return *this; }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::operator+ (ElemType alpha) const { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignSumOf(const ElemType alpha, const GPUMatrix<ElemType>& /*a*/)
    {
        return (*this);
    }


    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator+= (const GPUMatrix<ElemType>& /*a*/)  { return *this; }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::operator+ (const GPUMatrix<ElemType>& /*a*/) const { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignSumOf(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/)
    {
        return (*this);
    }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator-= (ElemType alpha)  { return *this; }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::operator- (ElemType alpha) const { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignDifferenceOf(const ElemType alpha, const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignDifferenceOf(const GPUMatrix<ElemType>& /*a*/, const ElemType alpha) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator-= (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::operator- (const GPUMatrix<ElemType>& /*a*/) const { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignDifferenceOf(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator*= (ElemType alpha) { return *this; }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::operator* (ElemType alpha) const { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignProductOf(const ElemType alpha, const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignProductOf (const GPUMatrix<ElemType>& /*a*/, const bool transposeA, const GPUMatrix<ElemType>& /*b*/, const bool transposeB) { return *this; }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::operator* (const GPUMatrix<ElemType>& /*a*/) const { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator/= (ElemType alpha)
    {
        return (*this);
    }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::operator/ (ElemType alpha) const { return *this; }

    //element-wise power
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::operator^= (ElemType alpha) { return *this; }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::operator^ (ElemType alpha) const { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignElementPowerOf(const GPUMatrix<ElemType>& /*a*/, const ElemType power) { return *this; }


    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AddElementProductOf (const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::ColumnElementMultiplyWith(const GPUMatrix<ElemType>& /*a*/) { return *this; }
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::RowElementMultiplyWith(const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::ColumnElementDivideBy(const GPUMatrix<ElemType>& /*a*/) { return *this; }
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::RowElementDivideBy(const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::ElementInverse () { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignElementInverseOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceSigmoid() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignSigmoidOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceSigmoidDerivative() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignSigmoidDerivativeOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }


    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceTanh() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignTanhOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceLogSoftmax (const bool isColWise)
    {
        return *this; 
    }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignLogSoftmaxOf (const GPUMatrix<ElemType>& /*a*/, const bool isColWise) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceSqrt() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignSqrtOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceExp() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignExpOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceLog() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignLogOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceAbs() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignAbsOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceLinearRectifierDerivative() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignLinearRectifierDerivativeOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceCosine() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignCosineOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceNegativeSine() { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignNegativeSineOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceTruncateBottom (const ElemType threshold) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignTruncateBottomOf (const GPUMatrix<ElemType>& /*a*/, const ElemType threshold) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::InplaceTruncateTop (const ElemType threshold)
    {
        return *this;        
    }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignTruncateTopOf (const GPUMatrix<ElemType>& /*a*/, const ElemType threshold)
    {
        return *this;        
    }
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::SetToZeroIfAbsLessThan (const ElemType threshold)
    {
        return *this;  
    }

    template<class ElemType> ElemType GPUMatrix<ElemType>::SumOfAbsElements() const
    {
        return ElemType(0);
    }

    template<class ElemType> ElemType GPUMatrix<ElemType>::SumOfElements() const
    {
        return ElemType(0);
    }

    
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignSumOfElements(const GPUMatrix<ElemType>& /*a*/)
    {
        return (*this);
    }

    template<class ElemType> DeviceBoundNumber<ElemType> GPUMatrix<ElemType>::Sum_AsDeviceBoundNum() const
    {
        DeviceBoundNumber<ElemType> result;
        return result;
    }

    template<class ElemType> ElemType GPUMatrix<ElemType>::Max() const
    {
        return ElemType(0);
    }


    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::ElementMultiplyWith (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignElementProductOf (const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignElementDivisionOf (const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/) { return *this; }
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::ElementDivideBy(const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> bool GPUMatrix<ElemType>::IsEqualTo(const GPUMatrix<ElemType>& a, const ElemType threshold /*= 1e-8*/) const
    {
        return AreEqual(*this, a, threshold);
    }

    template<class ElemType> void GPUMatrix<ElemType>::VectorNorm1(GPUMatrix<ElemType>& c, const bool isColWise) const
    {
    }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignVectorNorm1Of(GPUMatrix<ElemType>& /*a*/, const bool isColWise) { return *this; }

    template<class ElemType> void GPUMatrix<ElemType>::VectorNorm2(GPUMatrix<ElemType>& c, const bool isColWise) const
    {}

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignVectorNorm2Of(GPUMatrix<ElemType>& /*a*/, const bool isColWise) { return *this; }

    template<class ElemType> void GPUMatrix<ElemType>::VectorNormInf(GPUMatrix<ElemType>& c, const bool isColWise) const
    {}

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignVectorNormInfOf(GPUMatrix<ElemType>& /*a*/, const bool isColWise) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignInnerProductOf(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, const bool isColWise) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignKhatriRaoProductOf(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/) { return *this; }

    //column-wise reshaped product. Used to compute KhatriRaoProduct Gradient
    //   this = reshape each column of a from (K1xK2,1) to (K1, K2) 
    //   if each column of a is not transposed, each (K1, K2) times each column of b (K2, frames).
    //   the output is a (K1, frames) matrix
    //   if each column of a is tranposed, each (K1, K2)^T times each column of b(K1, frames) and output is (K2, frames)
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AddColumnReshapeProductOf(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, const bool transposeAColumn) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AddWithScaleOf(ElemType alpha, const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> ElemType GPUMatrix<ElemType>::FrobeniusNorm() const
    {
        ElemType h_sum=0;
        return (h_sum); 
    }
    
    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignFrobeniusNormOf (const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> ElemType GPUMatrix<ElemType>::MatrixNormInf() const
    {
        ElemType h_maxAbs=0;
        return h_maxAbs; 
    }

    template<class ElemType> ElemType GPUMatrix<ElemType>::MatrixNorm1() const
    {
        return ElemType(0);              
    }

    template<class ElemType> ElemType GPUMatrix<ElemType>::MatrixNorm0() const
    {
        return ElemType(0);              
    }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignSignOf(const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AddSignOf(const GPUMatrix<ElemType>& /*a*/) { return *this; }

    template<class ElemType> void GPUMatrix<ElemType>::VectorMax(GPUMatrix<ElemType>& maxIndexes, GPUMatrix<ElemType>& maxValues, const bool isColWise) const
    {}

    template<class ElemType> void GPUMatrix<ElemType>::VectorMin(GPUMatrix<ElemType>& minIndexes, GPUMatrix<ElemType>& minValues, const bool isColWise) const
    {}

    template<class ElemType> GPUMatrix<ElemType>&  GPUMatrix<ElemType>::AssignNumOfDiff(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/) { return *this; }

#pragma endregion Member BLAS Functions    

#pragma region Other helper functions
    template<class ElemType> void GPUMatrix<ElemType>::Print(const char* matrixName, size_t rowStart, size_t rowEnd, size_t colStart, size_t colEnd) const
    {}

    template<class ElemType> void GPUMatrix<ElemType>::Print(const char* matrixName /*=nullptr*/) const
    {}

    // file I/O
    //matrixName is used to verify that correct matrix is read.
    template<class ElemType> void GPUMatrix<ElemType>::ReadFromFile(FILE* f, const char * matrixName) 
    {}

    //matrixName is used to verify that correct matrix is read.
    template<class ElemType> void GPUMatrix<ElemType>::WriteToFile(FILE* f, const char * matrixName) 
    {}

    //helpfer function used for convolution neural network 
    template<class ElemType> GPUMatrix<ElemType>&  GPUMatrix<ElemType>::AssignPackedConvolutionInput(const GPUMatrix<ElemType>& inputSubBatch, 
                                            const size_t inputWidth, const size_t inputHeight, const size_t inputChannels,
                                            const size_t outputWidth, const size_t outputHeight, const size_t outputChannels,
                                            const size_t kernelWidth, const size_t kernelHeight, const size_t horizontalSubsample, const size_t verticalSubsample, 
                                            const bool zeroPadding) { return *this; }

    //helpfer function used for convolution neural network 
    template<class ElemType> GPUMatrix<ElemType>&  GPUMatrix<ElemType>::UnpackConvolutionInput(GPUMatrix<ElemType>& inputSubBatch, 
                                            const size_t inputWidth, const size_t inputHeight, const size_t inputChannels,
                                            const size_t outputWidth, const size_t outputHeight, const size_t outputChannels,
                                            const size_t kernelWidth, const size_t kernelHeight, const size_t horizontalSubsample, const size_t verticalSubsample, 
                                            const bool zeroPadding) const
    {
        return inputSubBatch;
    }

    template<class ElemType> GPUMatrix<ElemType>&  GPUMatrix<ElemType>::AssignMaxPoolingResult(const GPUMatrix<ElemType>& inputBatch, const size_t channels, 
                                                const size_t inputWidth, const size_t inputHeight, const size_t inputSizePerSample, 
                                                const size_t outputWidth, const size_t outputHeight, const size_t outputSizePerSample, 
                                                const size_t windowWidth, const size_t windowHeight, const size_t horizontalSubsample, const size_t verticalSubsample) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>&  GPUMatrix<ElemType>::AddMaxPoolingGradient(const GPUMatrix<ElemType>& outputGradientBatch, const GPUMatrix<ElemType>& inputBatch, const GPUMatrix<ElemType>& outputBatch, 
                                                const size_t channels, 
                                                const size_t inputWidth, const size_t inputHeight, const size_t inputSizePerSample, 
                                                const size_t outputWidth, const size_t outputHeight, const size_t outputSizePerSample, 
                                                const size_t windowWidth, const size_t windowHeight, const size_t horizontalSubsample, const size_t verticalSubsample) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>&  GPUMatrix<ElemType>::AssignAveragePoolingResult(const GPUMatrix<ElemType>& inputBatch, const size_t channels, 
                                                const size_t inputWidth, const size_t inputHeight, const size_t inputSizePerSample, 
                                                const size_t outputWidth, const size_t outputHeight, const size_t outputSizePerSample, 
                                                const size_t windowWidth, const size_t windowHeight, const size_t horizontalSubsample, const size_t verticalSubsample) { return *this; }

    template<class ElemType> GPUMatrix<ElemType>&  GPUMatrix<ElemType>::AddAveragePoolingGradient(const GPUMatrix<ElemType>& outputGradientBatch, 
                                                const size_t channels, 
                                                const size_t inputWidth, const size_t inputHeight, const size_t inputSizePerSample, 
                                                const size_t outputWidth, const size_t outputHeight, const size_t outputSizePerSample, 
                                                const size_t windowWidth, const size_t windowHeight, const size_t horizontalSubsample, const size_t verticalSubsample) { return *this; }

#pragma endregion Other helper functions

#pragma region Static BLAS Functions
    template<class ElemType> void GPUMatrix<ElemType>::MultiplyAndWeightedAdd(ElemType alpha, const GPUMatrix<ElemType>& /*a*/, const bool transposeA, const GPUMatrix<ElemType>& /*b*/, const bool transposeB, 
        ElemType beta, GPUMatrix<ElemType>& c)
    {
    }

    template<class ElemType> void GPUMatrix<ElemType>::MultiplyAndAdd(const GPUMatrix<ElemType>& /*a*/, const bool transposeA, const GPUMatrix<ElemType>& /*b*/, const bool transposeB, GPUMatrix<ElemType>& c) { }

    template<class ElemType> void GPUMatrix<ElemType>::Multiply(const GPUMatrix<ElemType>& /*a*/, const bool transposeA, const GPUMatrix<ElemType>& /*b*/, const bool transposeB, GPUMatrix<ElemType>& c) { }

    template<class ElemType> void GPUMatrix<ElemType>::Multiply(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, GPUMatrix<ElemType>& c) { }

    /// <summary>Matrix-scalar multiply with col-major matrices: c = alpha * a + c</summary>
    /// if a is a column vector, add to all columns of c 
    /// if a is a row vector, add to all rows of c    
    /// if a is a scalar, add to all elements of c
    /// <param name="alpha">Scalar</param>
    /// <param name="a">Input matrix</param>
    /// <param name="c">Resulting matrix, user is responsible for allocating this</param>
    template<class ElemType> void GPUMatrix<ElemType>::ScaleAndAdd(ElemType alpha,const GPUMatrix<ElemType>& /*a*/, GPUMatrix<ElemType>& c) { }

    /// <summary>c += alpha * (a-b)</summary>
    /// if a, b, c  must have same dim 
    /// <param name="alpha">Scalar</param>
    /// <param name="a">Input matrix</param>
    /// <param name="b">Input matrix</param>
    /// <param name="c">Resulting matrix, user is responsible for allocating this</param>
    template<class ElemType> void GPUMatrix<ElemType>::AddScaledDifference(const ElemType alpha, const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, GPUMatrix<ElemType>& c) { }

    /// <summary> c = alpha * (a-b)</summary>
    /// if a, b, c  must have same dim 
    /// <param name="alpha">Scalar</param>
    /// <param name="a">Input matrix</param>
    /// <param name="b">Input matrix</param>
    /// <param name="c">Resulting matrix, user is responsible for allocating this</param>
    template<class ElemType>    
    void GPUMatrix<ElemType>::AssignScaledDifference(const ElemType alpha, const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, GPUMatrix<ElemType>& c) { }

    /// <summary>c += alpha * (a-b)</summary>
    /// if a, b, c  must have same dim 
    /// <param name="alpha">1X1 matrix</param>
    /// <param name="a">Input matrix</param>
    /// <param name="b">Input matrix</param>
    /// <param name="c">Resulting matrix, user is responsible for allocating this</param>
    template<class ElemType> void GPUMatrix<ElemType>::AddScaledDifference(const GPUMatrix<ElemType>& /*alpha*/, const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, GPUMatrix<ElemType>& c) { }

    /// <summary> c = alpha * (a-b)</summary>
    /// if a, b, c  must have same dim 
    /// <param name="alpha">Scalar</param>
    /// <param name="a">Input matrix</param>
    /// <param name="b">Input matrix</param>
    /// <param name="c">Resulting matrix, user is responsible for allocating this</param>
    template<class ElemType>    
    void GPUMatrix<ElemType>::AssignScaledDifference(const GPUMatrix<ElemType>& /*alpha*/, const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, GPUMatrix<ElemType>& c) { }

    //c[ci,cj] += a[ai,aj]
    template<class ElemType> void GPUMatrix<ElemType>::AddElementToElement(const GPUMatrix<ElemType>& /*a*/, const size_t ai, const size_t aj, GPUMatrix<ElemType>& c, const size_t ci, const size_t cj) { }

    template<class ElemType> void GPUMatrix<ElemType>::Scale(ElemType alpha, GPUMatrix<ElemType>& /*a*/) { }


    template<class ElemType> void GPUMatrix<ElemType>::Scale(GPUMatrix<ElemType>& /*alpha*/, GPUMatrix<ElemType>& /*a*/) { }

    template<class ElemType> //c = alpha * a
    void GPUMatrix<ElemType>::Scale(ElemType alpha, const GPUMatrix<ElemType>& /*a*/, GPUMatrix<ElemType>& c) { }


    template<class ElemType> void GPUMatrix<ElemType>::InnerProduct (const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, GPUMatrix<ElemType>& c, const bool isColWise) { }

    template<class ElemType> ElemType GPUMatrix<ElemType>::InnerProductOfMatrices(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/)
    {
        return ElemType(0);
    }


    template<class ElemType> GPUMatrix<ElemType>& GPUMatrix<ElemType>::AssignInnerProductOfMatrices(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/) { return *this; }


    template<class ElemType> void GPUMatrix<ElemType>::ElementWisePower(ElemType alpha, const GPUMatrix<ElemType>& /*a*/, GPUMatrix<ElemType>& c) { }

    template<class ElemType> bool GPUMatrix<ElemType>::AreEqual(const GPUMatrix<ElemType>& /*a*/, const GPUMatrix<ElemType>& /*b*/, const ElemType threshold /*= 1e-8*/)
    {
            return false;
    }

    template<class ElemType> GPUMatrix<ElemType>  GPUMatrix<ElemType>::Ones(const size_t rows, const size_t cols)
    {
        GPUMatrix<ElemType> mat;
        return mat;
    }

    template<class ElemType> GPUMatrix<ElemType>  GPUMatrix<ElemType>::Zeros(const size_t rows, const size_t cols)
    {
        GPUMatrix<ElemType> mat;
        return mat;
    }

    template<class ElemType> GPUMatrix<ElemType>  GPUMatrix<ElemType>::Eye(const size_t rows)
    {
        GPUMatrix<ElemType> mat;
        return mat;
    }

    template<class ElemType> GPUMatrix<ElemType>  GPUMatrix<ElemType>::RandomUniform(const size_t rows, const size_t cols, const ElemType low, const ElemType high, unsigned long seed)
    {
        GPUMatrix<ElemType> mat;
        return mat;
    }

    template<class ElemType> GPUMatrix<ElemType> GPUMatrix<ElemType>::RandomGaussian(const size_t rows, const size_t cols, const ElemType mean, const ElemType sigma, unsigned long seed)
    {
        GPUMatrix<ElemType> mat;
        return mat;
    }

    template<class ElemType> ElemType GPUMatrix<ElemType>::GetLearnRateForBlock_Helper(const GPUMatrix<ElemType> &Gradients, const GPUMatrix<ElemType> &SmoothedGradients)
    {                
        return ElemType(0);
    }

#pragma endregion Static BLAS Functions

    template class GPUMatrix<float>; 
    template class GPUMatrix<double>;
    template class DeviceBoundNumber<float>;
    template class DeviceBoundNumber<double>;

    template<class ElemType> cublasHandle_t GPUMatrix<ElemType>::s_cuHandle[GPUMatrix<ElemType>::MaxGpus]={0};

    template<class ElemType> void* GPUMatrix<ElemType>::s_curandGenerator=NULL;    
}}}

// define a dummy GPUWatcher class too
#include "GPUWatcher.h"

int GPUWatcher::GetGPUIdWithTheMostFreeMemory()
{
    return 0;
}


size_t GPUWatcher::GetFreeMemoryOnCUDADevice(int /*devId*/)
{
    return 0;
}

GPUWatcher::GPUWatcher(void)
{
}

GPUWatcher::~GPUWatcher(void)
{
}

#endif  // CPUONLY