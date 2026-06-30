#pragma once

/***************************************************************
 * This source files comes from the xLights project
 * https://www.xlights.org
 * https://github.com/xLightsSequencer/xLights
 * See the github commit history for a record of contributing
 * developers.
 * Copyright claimed based on commit dates recorded in Github
 * License: https://github.com/xLightsSequencer/xLights/blob/master/License.txt
 **************************************************************/

#include <vector>
#include <string>
#include <functional>

class Model;

struct UserPixelProfile {
	std::string name;
	double voltage = 0.0;
	double wattsPer100Pixels = 0.0;
};

std::string ChooseBestControllerPixel(const std::vector<std::string>& controllerPixels, const std::string& selectedPixel);
std::vector<std::string> GetAllPixelTypes(bool includeSerial = false, bool includeArtificial = true, bool includeMatrices = true);
std::vector<std::string> GetAllPixelTypes(const std::vector<std::string>& controllerPixels, bool includeSerial, bool includeArtificial, bool includeMatrices);
std::vector<std::string> GetAllSerialTypes();
std::vector<std::string> GetAllSerialTypes(const std::vector<std::string>& controllerSerial);
std::string ChooseBestControllerSerial(const std::vector<std::string>& controllerSerial, const std::string& selectedSerial);
bool IsArtificialPixelType(const std::string& p);
bool IsPixelProtocol(const std::string& p);
bool IsSerialProtocol(const std::string& p);
bool IsMatrixProtocol(const std::string& p1);
bool IsPWMProtocol(const std::string& p1);
bool IsLEDPanelMatrixProtocol(const std::string& p1);
bool IsVirtualMatrixProtocol(const std::string& p1);
int GetChannelsPerPixel(const std::string& p);

std::vector<UserPixelProfile> DeserializeUserPixelProfiles(const std::string& encodedProfiles);
std::string SerializeUserPixelProfiles(const std::vector<UserPixelProfile>& profiles);
std::vector<std::string> GetUserPixelProfileNames(const std::vector<UserPixelProfile>& profiles);
const UserPixelProfile* FindUserPixelProfileByName(const std::vector<UserPixelProfile>& profiles, const std::string& profileName);

void SetUserPixelProfileCatalogProvider(const std::function<std::string()>& provider);
double GetModelPowerLimit(const Model& model);
