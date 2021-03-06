/*
 * ObservableFactory.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: rovigatti
 */

#include "ObservableFactory.h"

#include "../PluginManagement/PluginManager.h"

#include "Step.h"
#include "PotentialEnergy.h"
#include "KineticEnergy.h"
#include "TotalEnergy.h"
#include "Configurations/Configuration.h"
#include "BackendInfo.h"
#include "HBEnergy.h"
#include "PairEnergy.h"
#include "PairForce.h"
#include "OrderParameterValues.h"
#include "HBList.h"
#include "StrandwiseBonds.h"
#include "ForceEnergy.h"
#include "Pressure.h"
#include "Density.h"
#include "DensityProfile.h"
#include "ParticlePosition.h"
#include "Rdf.h"
#include "Distance.h"
#include "CoaxVariables.h"
#include "Pitch.h"
#include "SaltExtrapolation.h"
#include "ExternalTorque.h"
#include "MeanVectorCosine.h"
#include "VectorAngle.h"
#include "Checkpoint.h"
#include "Contacts.h"
#include "Writhe.h"
#include "UnstackedList.h"
#include "PlectonemePosition.h"
#include "StretchedBonds.h"
#include "StructureFactor.h"
#include "FormFactor.h"
#include "UnstackedList.h"
#include "PlectonemePosition.h"
#include "TEPPlectonemePosition.h"
#include "AverageEnergy.h"
#include "ContactMap.h"
#include "AllVectors.h"

#include "Configurations/PdbOutput.h"
#include "Configurations/ChimeraOutput.h"
#include "Configurations/BinaryConfiguration.h"
#include "Configurations/TclOutput.h"
#include "Configurations/TEPtclOutput.h"
#include "Configurations/TEPxyzOutput.h"
#include "Configurations/JordanOutput.h"

ObservablePtr ObservableFactory::make_observable(input_file &obs_inp) {
	char obs_type[512];
	getInputString(&obs_inp, "type", obs_type, 1);

	ObservablePtr res = nullptr;

	if(!strncasecmp(obs_type, "step", 512)) res = std::make_shared<Step>();
	else if(!strncasecmp(obs_type, "potential_energy", 512)) res = std::make_shared<PotentialEnergy>();
	else if(!strncasecmp(obs_type, "kinetic_energy", 512)) res = std::make_shared<KineticEnergy>();
	else if(!strncasecmp(obs_type, "total_energy", 512)) res = std::make_shared<TotalEnergy>();
	else if(!strncasecmp(obs_type, "backend_info", 512)) res = std::make_shared<BackendInfo>();
	else if(!strncasecmp(obs_type, "configuration", 512)) res = std::make_shared<Configuration>();
	else if(!strncasecmp(obs_type, "hb_energy", 512)) res = std::make_shared<HBEnergy>();
	else if(!strncasecmp(obs_type, "pair_energy", 512)) res = std::make_shared<PairEnergy>();
	else if(!strncasecmp(obs_type, "pair_force", 512)) res = std::make_shared<PairForce>();
	else if(!strncasecmp(obs_type, "hb_list", 512)) res = std::make_shared<HBList>();
	else if(!strncasecmp(obs_type, "order_parameters", 512)) res = std::make_shared<OrderParameterValues>();
	else if(!strncasecmp(obs_type, "strandwise_bonds", 512)) res = std::make_shared<StrandwiseBonds>();
	else if(!strncasecmp(obs_type, "force_energy", 512)) res = std::make_shared<ForceEnergy>();
	else if(!strncasecmp(obs_type, "binary_configuration", 512)) res = std::make_shared<BinaryConfiguration>();
	else if(!strncasecmp(obs_type, "tcl_configuration", 512)) res = std::make_shared<TclOutput>();
	else if(!strncasecmp(obs_type, "pressure", 512)) res = std::make_shared<Pressure>();
	else if(!strncasecmp(obs_type, "density", 512)) res = std::make_shared<Density>();
	else if(!strncasecmp(obs_type, "density_profile", 512)) res = std::make_shared<DensityProfile>();
	else if(!strncasecmp(obs_type, "rdf", 512)) res = std::make_shared<Rdf>();
	else if(!strncasecmp(obs_type, "particle_position", 512)) res = std::make_shared<ParticlePosition>();
	else if(!strncasecmp(obs_type, "distance", 512)) res = std::make_shared<Distance>();
	else if(!strncasecmp(obs_type, "pdb_configuration", 512)) res = std::make_shared<PdbOutput>();
	else if(!strncasecmp(obs_type, "chimera_script", 512)) res = std::make_shared<ChimeraOutput>();
	else if(!strncasecmp(obs_type, "coax_variables", 512)) res = std::make_shared<CoaxVariables>();
	else if(!strncasecmp(obs_type, "pitch", 512)) res = std::make_shared<Pitch>();
	else if(!strncasecmp(obs_type, "salt_extrapolation", 512)) res = std::make_shared<SaltExtrapolation>();
	else if(!strncasecmp(obs_type, "external_torque", 512)) res = std::make_shared<ExternalTorque>();
	else if(!strncasecmp(obs_type, "mean_vector_cosine", 512)) res = std::make_shared<MeanVectorCosine>();
	else if(!strncasecmp(obs_type, "vector_angle", 512)) res = std::make_shared<VectorAngle>();
	else if(!strncasecmp(obs_type, "TEPtcl_configuration", 512)) res = std::make_shared<TEPtclOutput>();
	else if(!strncasecmp(obs_type, "TEPxyz_configuration", 512)) res = std::make_shared<TEPxyzOutput>();
	else if(!strncasecmp(obs_type, "checkpoint", 512)) res = std::make_shared<Checkpoint>();
	else if(!strncasecmp(obs_type, "contacts", 512)) res = std::make_shared<Contacts>();
	else if(!strncasecmp(obs_type, "writhe", 512)) res = std::make_shared<Writhe>();
	else if(!strncasecmp(obs_type, "stretched", 512)) res = std::make_shared<StretchedBonds>();
	else if(!strncasecmp(obs_type, "jordan_conf", 512)) res = std::make_shared<JordanOutput>();
	else if(!strncasecmp(obs_type, "unstacked_list", 512)) res = std::make_shared<UnstackedList>();
	else if(!strncasecmp(obs_type, "plectoneme_position", 512)) res = std::make_shared<PlectonemePosition>();
	else if(!strncasecmp(obs_type, "TEP_plectoneme_position", 512)) res = std::make_shared<TEPPlectonemePosition>();
	else if(!strncasecmp(obs_type, "Sq", 512)) res = std::make_shared<StructureFactor>();
	else if(!strncasecmp(obs_type, "Pq", 512)) res = std::make_shared<FormFactor>();
	else if(!strncasecmp(obs_type, "unstacked_list", 512)) res = std::make_shared<UnstackedList>();
	else if(!strncasecmp(obs_type, "plectoneme_position", 512)) res = std::make_shared<PlectonemePosition>();
	else if(!strncasecmp(obs_type, "average_energy", 512)) res = std::make_shared<AverageEnergy>();
	else if(!strncasecmp(obs_type, "contact_map", 512)) res = std::make_shared<ContactMap>();
	else if(!strncasecmp(obs_type, "all_vectors", 512)) res = std::make_shared<AllVectors>();
	else {
		res = PluginManager::instance()->get_observable(obs_type);
		if(res == NULL) throw oxDNAException("Observable '%s' not found. Aborting", obs_type);
	}

	res->get_settings(obs_inp, *(CONFIG_INFO->sim_input));

	return res;
}
