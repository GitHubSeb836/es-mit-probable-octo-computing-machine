// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#include "stdafx.h"

using namespace std;
using namespace Common;
using namespace TXRStatefulServiceBase;
using namespace TpccService;
using namespace TxnReplicator;
using namespace Data::Utilities;

static const ULONG INT_SL_TAG = 'insl';

IntSerializer::IntSerializer()
{

}

IntSerializer::~IntSerializer()
{

}

NTSTATUS IntSerializer::Create(
    __in KAllocator& allocator,
    __out SPtr& result)
{
    NTSTATUS status;
    SPtr output = _new(INT_SL_TAG, allocator) IntSerializer();

    if (output == nullptr)
    {
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    status = output->Status();
    if (!NT_SUCCESS(status))
    {
        return status;
    }

    result = Ktl::Move(output);
    return STATUS_SUCCESS;
}

void IntSerializer::Write(
    __in int value,
    __in BinaryWriter& binaryWriter)
{
    binaryWriter.Write(value);
}

int IntSerializer::Read(
    __in BinaryReader& binaryReader)
{
    int value = 0;
    binaryReader.Read(value);
    return value;
}
