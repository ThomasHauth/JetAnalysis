/* Copyright (c) 2013 - All Rights Reserved
 *   Thomas Hauth  <Thomas.Hauth@cern.ch>
 *   Joram Berger  <Joram.Berger@cern.ch>
 *   Dominik Haitz <Dominik.Haitz@kit.edu>
 */

#pragma once

#include "Artus/Core/interface/Cpp11Support.h"

#include "JetTypes.h"

class PtFilter: public JetFilterBase {
public:

	virtual ~PtFilter() {
	}

	virtual std::string GetFilterId() {
		return "filter_pt";
	}

	virtual bool DoesEventPass(JetEvent const& event,
			JetGlobalProduct const& globalProduct,
			JetPipelineSettings const& settings) {

		const float lowCut = settings.GetFilterPtLow();
		const float highCut = settings.GetFilterPtHigh();

		assert(lowCut <= highCut);

		return ((lowCut <= event.m_floatPtSim) && (highCut > event.m_floatPtSim));
	}
};
