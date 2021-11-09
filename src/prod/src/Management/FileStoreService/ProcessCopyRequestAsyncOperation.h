// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace Management
{
    namespace FileStoreService
    {        
        class ProcessCopyRequestAsyncOperation : public ProcessRequestAsyncOperation
        {
            DENY_COPY(ProcessCopyRequestAsyncOperation)

        public:
            ProcessCopyRequestAsyncOperation(
                __in RequestManager & requestManager,
                CopyRequest && copyMessage,
                Transport::IpcReceiverContextUPtr && receiverContext,
                Common::ActivityId const & activityId,
                Common::TimeSpan const & timeout,
                Common::AsyncCallback const &,
                Common::AsyncOperationSPtr const &);
            virtual ~ProcessCopyRequestAsyncOperation();

        protected:
            Common::ErrorCode ValidateRequest();

            Common::AsyncOperationSPtr BeginOperation(
                Common::AsyncCallback const & callback,
                Common::AsyncOperationSPtr const & parent);

            Common::ErrorCode EndOperation(
                __out Transport::MessageUPtr & reply,
                Common::AsyncOperationSPtr const & asyncOperation);

        private:
            bool const shouldOverwrite_;
            std::wstring const sourceStoreRelativePath_;
            StoreFileVersion const sourceFileVersion_;
        };
    }
}
