/* Copyright (c) 2013 - All Rights Reserved
 *   Thomas Hauth  <Thomas.Hauth@cern.ch>
 *   Joram Berger  <Joram.Berger@cern.ch>
 *   Dominik Haitz <Dominik.Haitz@kit.edu>
 */

#pragma once

#include "Artus/Core/interface/Cpp11Support.h"

#include "Artus/Consumer/interface/NtupleConsumerBase.h"

#include "JetTypes.h"


class JetNtupleConsumer: public NtupleConsumerBase<JetTypes> {
private:
	
	float returnvalue(std::string string, JetEvent const& event,
			JetGlobalProduct const& globalProduct,
			JetLocalProduct const& localProduct) ARTUS_CPP11_OVERRIDE
	{
		if (string == "pt")
			return event.m_floatPtSim;
		else if (string == "pt_corr")
			return globalProduct.m_floatPtSim_corrected;
		else if (string == "theta")
			return event.m_floatTheSim;
		else
			LOG_FATAL("The quantity " << string << " could not be added to the Ntuple")
	}


};
