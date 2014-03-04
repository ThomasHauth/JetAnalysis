/* Copyright (c) 2013 - All Rights Reserved
 *   Thomas Hauth  <Thomas.Hauth@cern.ch>
 *   Joram Berger  <Joram.Berger@cern.ch>
 *   Dominik Haitz <Dominik.Haitz@kit.edu>
 */

#pragma once

#include "Artus/Core/interface/GlobalInclude.h"
#include "Artus/Configuration/interface/SettingsBase.h"
#include "Artus/Configuration/interface/SettingMacros.h"
#include "Artus/Configuration/interface/PropertyTreeSupport.h"
#include "Artus/KappaAnalysis/interface/KappaPipelineSettings.h"

class JetPipelineSettings: public KappaPipelineSettings {
public:

	IMPL_SETTING( float, FilterPtLow )
	IMPL_SETTING( float, FilterPtHigh )

	VarCache<stringvector> m_consumer;
	stringvector GetConsumer() const
	{
		RETURN_CACHED(m_consumer, PropertyTreeSupport::GetAsStringList(GetPropTree(), "Pipelines." + GetName() + ".Consumer"))
	}

	VarCache<stringvector> quantities;
	stringvector GetQuantities() const
	{
		RETURN_CACHED(quantities, PropertyTreeSupport::GetAsStringList(GetPropTree(), "Pipelines." + GetName() + ".Quantities"))
	}

};

class JetGlobalSettings: public KappaGlobalSettings {
public:
	IMPL_SETTING_DEFAULT(std::string, Jets, "");
	IMPL_SETTING( float, ProducerPtCorrectionFactor )

};
