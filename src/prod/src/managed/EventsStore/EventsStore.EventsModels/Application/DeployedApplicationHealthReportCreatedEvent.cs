// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

namespace EventsStore.EventsModels.Application
{
    using System;
    using Newtonsoft.Json;
    using Microsoft.ServiceFabric.Instrumentation.Tracing.Definitions.TypedTraceRecords.HM;

    [JsonObject("DeployedApplicationNewHealthReport")]
    public sealed class DeployedApplicationHealthReportCreatedEvent : ApplicationEvent
    {
        public DeployedApplicationHealthReportCreatedEvent(DeployedApplicationHealthReportCreatedTraceRecord traceRecord) : base(traceRecord.EventInstanceId, traceRecord.TimeStamp, traceRecord.Category, traceRecord.ApplicationName)
        {
            this.ApplicationInstanceId = traceRecord.ApplicationInstanceId;
            this.NodeName = traceRecord.NodeName;
            this.SourceId = traceRecord.SourceId;
            this.Property = traceRecord.Property;
            this.HealthState = traceRecord.HealthState.ToString();
            this.TimeToLiveMs = traceRecord.TTLTimespan;
            this.SequenceNumber = traceRecord.SequenceNumber;
            this.Description = traceRecord.Description;
            this.RemoveWhenExpired = traceRecord.RemoveWhenExpired;
            this.SourceUtcTimestamp = traceRecord.SourceUtcTimestamp;
        }

        [JsonProperty(PropertyName = "ApplicationInstanceId")]
        public long ApplicationInstanceId { get; set; }

        [JsonProperty(PropertyName = "NodeName")]
        public string NodeName { get; set; }

        [JsonProperty(PropertyName = "SourceId")]
        public string SourceId { get; set; }

        [JsonProperty(PropertyName = "Property")]
        public string Property { get; set; }

        [JsonProperty(PropertyName = "HealthState")]
        public string HealthState { get; set; }

        [JsonProperty(PropertyName = "TimeToLiveMs")]
        public long TimeToLiveMs { get; set; }

        [JsonProperty(PropertyName = "SequenceNumber")]
        public long SequenceNumber { get; set; }

        [JsonProperty(PropertyName = "Description")]
        public string Description { get; set; }

        [JsonProperty(PropertyName = "RemoveWhenExpired")]
        public bool RemoveWhenExpired { get; set; }

        [JsonProperty(PropertyName = "SourceUtcTimestamp")]
        public DateTime SourceUtcTimestamp { get; set; }
    }
}
