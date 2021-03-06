/* Copyright (c) 2013 - All Rights Reserved
 *   Thomas Hauth  <Thomas.Hauth@cern.ch>
 *   Joram Berger  <Joram.Berger@cern.ch>
 *   Dominik Haitz <Dominik.Haitz@kit.edu>
 */

#pragma once

#include "Artus/Core/interface/Cpp11Support.h"
#include "Artus/KappaAnalysis/interface/KappaFactory.h"


#include "JetTypes.h"

#include "JetSettings.h"
#include "JetEvent.h"
#include "JetProduct.h"

class JetFactory: public KappaFactory<JetTypes> {
public:

	JetFactory();
	~JetFactory();
	virtual JetProducerBase * createProducer ( std::string const& id ) ARTUS_CPP11_OVERRIDE;
	virtual JetConsumerBase * createConsumer ( std::string const& id ) ARTUS_CPP11_OVERRIDE;
	virtual JetFilterBase * createFilter ( std::string const& id ) ARTUS_CPP11_OVERRIDE;

};

