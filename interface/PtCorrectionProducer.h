/* Copyright (c) 2013 - All Rights Reserved
 *   Thomas Hauth  <Thomas.Hauth@cern.ch>
 *   Joram Berger  <Joram.Berger@cern.ch>
 *   Dominik Haitz <Dominik.Haitz@kit.edu>
 */

#pragma once

#include "Artus/Core/interface/Cpp11Support.h"

#include "JetTypes.h"

class PtCorrectionProducer: public JetGlobalProducerBase {
public:

	virtual bool ProduceGlobal(JetEvent const& event,
			JetProduct & product,
			JetGlobalSettings const& globalSettings) const
					ARTUS_CPP11_OVERRIDE {

		product.m_floatPtSim_corrected = event.m_floatPtSim
				* globalSettings.GetProducerPtCorrectionFactor();

		return true;
	}

};
