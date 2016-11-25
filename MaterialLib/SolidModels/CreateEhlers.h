/**
 * \copyright
 * Copyright (c) 2012-2016, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#ifndef MATERIALLIB_SOLIDMODELS_CREATEEHLERS_H_
#define MATERIALLIB_SOLIDMODELS_CREATEEHLERS_H_

#include <logog/include/logog.hpp>

#include "MechanicsBase.h"
#include "ProcessLib/Utils/ProcessUtils.h"  // required for findParameter
#include "Ehlers.h"

namespace MaterialLib
{
namespace Solids
{
template <int DisplacementDim>
std::unique_ptr<MechanicsBase<DisplacementDim>> createEhlers(
    std::vector<std::unique_ptr<ProcessLib::ParameterBase>> const& parameters,
    BaseLib::ConfigTree const& config)
{
    config.checkConfigParameter("type", "Ehlers");
    DBUG("Create Ehlers material");

    auto& shear_modulus = ProcessLib::findParameter<double>(
        config, "shear_modulus", parameters, 1);

    DBUG("Use \'%s\' as shear modulus parameter.", shear_modulus.name.c_str());

    auto& bulk_modulus = ProcessLib::findParameter<double>(
        config, "bulk_modulus", parameters, 1);

    DBUG("Use \'%s\' as bulk modulus parameter.", bulk_modulus.name.c_str());

    auto& kappa = ProcessLib::findParameter<double>(
        config, "kappa", parameters, 1);

    DBUG("Use \'%s\' as kappa.",
         kappa.name.c_str());

    auto& beta = ProcessLib::findParameter<double>(
        config, "beta", parameters, 1);

    DBUG("Use \'%s\' as beta.",
         beta.name.c_str());

    auto& gamma = ProcessLib::findParameter<double>(
        config, "gamma", parameters, 1);

    DBUG("Use \'%s\' as gamma.",
         gamma.name.c_str());

    auto& hardening_modulus = ProcessLib::findParameter<double>(
        config, "hardening_modulus", parameters, 1);

    DBUG("Use \'%s\' as hardening modulus parameter.",
         hardening_modulus.name.c_str());

    auto& alpha = ProcessLib::findParameter<double>(
        config, "alpha", parameters, 1);

    DBUG("Use \'%s\' as alpha.",
         alpha.name.c_str());

    auto& delta = ProcessLib::findParameter<double>(
        config, "delta", parameters, 1);

    DBUG("Use \'%s\' as delta.",
         delta.name.c_str());

    auto& eps = ProcessLib::findParameter<double>(
        config, "eps", parameters, 1);

    DBUG("Use \'%s\' as eps.",
         eps.name.c_str());

    auto& m = ProcessLib::findParameter<double>(
        config, "m", parameters, 1);

    DBUG("Use \'%s\' as m.",
         m.name.c_str());

    auto& alphap = ProcessLib::findParameter<double>(
        config, "alphap", parameters, 1);

    DBUG("Use \'%s\' as alphap.",
         alphap.name.c_str());

    auto& deltap = ProcessLib::findParameter<double>(
        config, "deltap", parameters, 1);

    DBUG("Use \'%s\' as deltap.",
         deltap.name.c_str());

    auto& epsp = ProcessLib::findParameter<double>(
        config, "epsp", parameters, 1);

    DBUG("Use \'%s\' as epsp.",
         epsp.name.c_str());

    auto& paremeter_mp = ProcessLib::findParameter<double>(
        config, "mp", parameters, 1);

    DBUG("Use \'%s\' as mp.",
         paremeter_mp.name.c_str());

    auto& betap = ProcessLib::findParameter<double>(
        config, "betap", parameters, 1);

    DBUG("Use \'%s\' as betap.",
         betap.name.c_str());

    auto& gammap = ProcessLib::findParameter<double>(
        config, "gammap", parameters, 1);

    DBUG("Use \'%s\' as gammap.",
         gammap.name.c_str());

    typename SolidEhlers<DisplacementDim>::MaterialProperties mp{
        shear_modulus, bulk_modulus, alpha,  beta,
        gamma,         delta,        eps,    m,
        alphap,        betap,        gammap, deltap,
        epsp,          paremeter_mp, kappa,  hardening_modulus};

    return std::unique_ptr<MechanicsBase<DisplacementDim>>{
        new SolidEhlers<DisplacementDim>{mp}};
}

}  // namespace Solids
}  // namespace MaterialLib

#endif  // MATERIALLIB_SOLIDMODELS_CREATEEHLERS_H_
