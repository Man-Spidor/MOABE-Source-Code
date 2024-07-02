#ifndef LIGHTATTORNEY_H
#define LIGHTATTORNEY_H

#include "MOABELight.h"
#include "LightBehaviourCommand.h"

class LightAttorney
{
	friend class LightManager;

	friend class NormalProcessor;
	friend class CullDistProcessor;
	friend class CullViewProcessor;

	friend class MOABELight;

	friend class DirectionalRegCmd;
	friend class DirectionalDeRegCmd;
	friend class PointRegCmd;
	friend class PointDeRegCmd;
	friend class SpotRegCmd;
	friend class SpotDeRegCmd;

	friend class LightAlarm;

	class Light 
	{
		friend class LightManager;
		friend class NormalProcessor;
		friend class CullDistProcessor;
		friend class CullViewProcessor;

		static void UpdateLight(MOABELight* pLight) { pLight->UpdateLight(); };
		
		friend class DirectionalRegCmd;
		friend class DirectionalDeRegCmd;
		friend class PointRegCmd;
		friend class PointDeRegCmd;
		friend class SpotRegCmd;
		friend class SpotDeRegCmd;

		static void SetRegStatusRegistered(MOABELight* pLight) { pLight->SetRegStatusRegistered(); };
		static void SetRegStatusDeregistered(MOABELight* pLight) { pLight->SetRegStatusDeregistered(); };
	};

	class Behaviour
	{
		friend class MOABELight;
		friend class LightAlarm;

		static void ProcessLight(LightBehaviourCommand* pCmd) { pCmd->ProcessLight(); };

		static void Callback0(LightBehaviourCommand& Cmd) { Cmd.Callback0(); };
		static void Callback1(LightBehaviourCommand& Cmd) { Cmd.Callback1(); };
		static void Callback2(LightBehaviourCommand& Cmd) { Cmd.Callback2(); };
	};
};

#endif // LIGHTATTORNEY_H