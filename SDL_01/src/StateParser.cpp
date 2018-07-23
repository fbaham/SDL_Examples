#include "StateParser.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObjectFactory.h"
#include "tinyxml2.h"

using namespace std;

bool StateParser::parseState(const char *stateFile, string stateID, vector<GameObject *> *pObjects, std::vector<std::string> *pTextureIDs)
{
	// create the XML document
	XMLDocument xmlDoc;
	// load the state file
	if(!xmlDoc.LoadFile(stateFile))
	{
		cerr << xmlDoc.ErrorStr() << "\n";
		//return false;
	}
	// get the root element
	XMLElement* pRoot = xmlDoc.RootElement();
	// pre declare the states root node
	XMLElement* pStateRoot = 0;
	// get this states root node and assign it to pStateRoot
	for(XMLElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}
	// pre declare the texture root
	XMLElement* pTextureRoot = 0;
	// get the root of the texture elements
	for(XMLElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}
	// now parse the textures
	parseTextures(pTextureRoot, pTextureIDs);
	// pre declare the object root node
	XMLElement* pObjectRoot = 0;
	// get the root node and assign it to pObjectRoot
	for(XMLElement* e = pStateRoot->FirstChildElement(); e !=	NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == string("OBJECTS"))
		{
			pObjectRoot = e;
		}
	}
	// now parse the objects
	parseObjects(pObjectRoot, pObjects);
	return true;
}

void StateParser::parseTextures(XMLElement* pStateRoot, std::vector<std::string> *pTextureIDs)
{
	for(XMLElement* e = pStateRoot->FirstChildElement(); e !=	NULL; e = e->NextSiblingElement())
	{
		string filenameAttribute = e->Attribute("filename");
		string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute); // push into list
		TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer());
	}
}

void StateParser::parseObjects(XMLElement *pStateRoot, std::vector<GameObject *> *pObjects)
{
	for(XMLElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, callbackID, animSpeed;
		string textureID;
		x = e->IntAttribute("x");
		y = e->IntAttribute("y");
		width = e->IntAttribute("width");
		height = e->IntAttribute("height");
		numFrames = e->IntAttribute("numFrames");
		callbackID = e->IntAttribute("callbackID");
		animSpeed = e->IntAttribute("animSpeed");
		textureID = e->Attribute("textureID");
		GameObject* pGameObject = TheGameObjectFactory::Instance() ->create(e->Attribute("type"));
		pGameObject->load(new LoaderParams (x,y,width,height,textureID,numFrames,callbackID, animSpeed));
		pObjects->push_back(pGameObject);
	}
}
