// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once 

namespace ServiceModel
{
    class DeployedServicePackageHealthEvaluation
        : public HealthEvaluationWithChildrenBase
    {
        DENY_COPY(DeployedServicePackageHealthEvaluation)

    public:
        DeployedServicePackageHealthEvaluation();

        DeployedServicePackageHealthEvaluation(
            std::wstring const & applicationName,
            std::wstring const & serviceManifestName,
            std::wstring const & servicePackageActivationId,
            std::wstring const & nodeName,
            FABRIC_HEALTH_STATE aggregatedHealthState,
            HealthEvaluationList && evaluations);

        DeployedServicePackageHealthEvaluation(DeployedServicePackageHealthEvaluation && other) = default;
        DeployedServicePackageHealthEvaluation & operator = (DeployedServicePackageHealthEvaluation && other) = default;

        virtual ~DeployedServicePackageHealthEvaluation();

        __declspec(property(get=get_ApplicationName)) std::wstring const& ApplicationName;
        std::wstring const& get_ApplicationName() const { return applicationName_; }

        __declspec(property(get=get_ServiceManifestName)) std::wstring const& ServiceManifestName;
        std::wstring const& get_ServiceManifestName() const { return serviceManifestName_; }

        __declspec(property(get = get_ServicePackageActivationId)) std::wstring const & ServicePackageActivationId;
        std::wstring const & get_ServicePackageActivationId() const { return servicePackageActivationId_; }

        __declspec(property(get=get_NodeName)) std::wstring const & NodeName;
        std::wstring const & get_NodeName() const { return nodeName_; }

        virtual void SetDescription() override;

        Common::ErrorCode ToPublicApi(
            __in Common::ScopedHeap & heap, 
            __out FABRIC_HEALTH_EVALUATION & publicHealthEvaluation) const;
        
        Common::ErrorCode FromPublicApi(
            FABRIC_HEALTH_EVALUATION const & publicHealthEvaluation);

        FABRIC_FIELDS_08(kind_, description_, unhealthyEvaluations_, aggregatedHealthState_, applicationName_, nodeName_, serviceManifestName_, servicePackageActivationId_);

        BEGIN_JSON_SERIALIZABLE_PROPERTIES()
            SERIALIZABLE_PROPERTY_CHAIN()
            SERIALIZABLE_PROPERTY(Constants::Name, applicationName_)
            SERIALIZABLE_PROPERTY(Constants::ServiceManifestName, serviceManifestName_)
            SERIALIZABLE_PROPERTY(Constants::NodeName, nodeName_)
            SERIALIZABLE_PROPERTY(Constants::UnhealthyEvaluations, unhealthyEvaluations_)
            SERIALIZABLE_PROPERTY(Constants::ServicePackageActivationId, servicePackageActivationId_)
        END_JSON_SERIALIZABLE_PROPERTIES()     

        BEGIN_DYNAMIC_SIZE_ESTIMATION()
            DYNAMIC_SIZE_ESTIMATION_CHAIN()
            DYNAMIC_SIZE_ESTIMATION_MEMBER(nodeName_)
            DYNAMIC_SIZE_ESTIMATION_MEMBER(applicationName_)
            DYNAMIC_SIZE_ESTIMATION_MEMBER(serviceManifestName_)
            DYNAMIC_SIZE_ESTIMATION_MEMBER(unhealthyEvaluations_)
            DYNAMIC_SIZE_ESTIMATION_MEMBER(servicePackageActivationId_)
        END_DYNAMIC_SIZE_ESTIMATION()

    private:
        std::wstring nodeName_;
        std::wstring applicationName_;
        std::wstring serviceManifestName_;
        std::wstring servicePackageActivationId_;
    };

    DEFINE_HEALTH_EVALUATION_ACTIVATOR(DeployedServicePackageHealthEvaluation, FABRIC_HEALTH_EVALUATION_KIND_DEPLOYED_SERVICE_PACKAGE)
}
