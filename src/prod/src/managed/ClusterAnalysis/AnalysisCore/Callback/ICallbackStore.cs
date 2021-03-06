// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

namespace ClusterAnalysis.AnalysisCore.Callback
{
    using System;
    using System.Collections.Generic;
    using System.Threading;
    using System.Threading.Tasks;

    /// <summary>
    /// Describes contract for any store implementation that support callbacks.
    /// </summary>
    internal interface ICallbackStore
    {
        /// <summary>
        /// Gets all the scenarios for which we callbacks are supported
        /// </summary>
        /// <returns>Collection of scenarios.</returns>
        IEnumerable<Scenario> GetCallbackSupportedScenario();

        /// <summary>
        /// Register callback with a specific filter
        /// </summary>
        /// <param name="notifyFilter"></param>
        /// <param name="callbackRoutine"></param>
        /// <param name="token"></param>
        /// <returns></returns>
        Task RegisterCallbackAsync(NotifyFilter notifyFilter, Func<ScenarioData, Task> callbackRoutine, CancellationToken token);

        /// <summary>
        /// Unregister a callback.
        /// </summary>
        /// <param name="notifyFilter"></param>
        /// <param name="callbackRoutine"></param>
        /// <param name="token"></param>
        /// <returns></returns>
        Task UnRegisterCallbackAsync(NotifyFilter notifyFilter, Func<ScenarioData, Task> callbackRoutine, CancellationToken token);

        /// <summary>
        /// Reset to Beginning. Basically lose all the internal progress state so that in future, can start from beginning.
        /// </summary>
        /// <returns></returns>
        Task ResetCheckpointAsync(CancellationToken token);
    }
}