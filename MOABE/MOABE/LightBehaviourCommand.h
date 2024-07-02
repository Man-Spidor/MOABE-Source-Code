#ifndef LIGHTBEHAVIOURCOMMAND_H
#define LIGHTBEHAVIOURCOMMAND_H

/// Abstract Class Used To Define Light Behaviour 
/// 
/// Class used to define how a light is updated every frame. By every Light has its behaviour 
/// set to @see LightBehaviourStatic. Meaning the light is not updated and stays exactly the same.
/// 
/// A Few Preset Light Behaviours Include:
/// @see PointLightTrackingCmd
/// @see SpotLightTrackingCmd
/// @see LightBlinkingCmd 
class LightBehaviourCommand
{
	friend class LightAttorney;

	class BehaviourStrategy
	{
	public:
		virtual void ProcessLight(LightBehaviourCommand& Behaviour) const = 0;
	};

	class StoppedBehaviour : public BehaviourStrategy
	{
	public:
		virtual void ProcessLight(LightBehaviourCommand& Behaviour) const override 
		{ 
			// do nothing
			UNREFERENCED_PARAMETER(Behaviour); 
		};
	};

	class NormalBehaviour : public BehaviourStrategy
	{
	public:
		virtual void ProcessLight(LightBehaviourCommand& Behaviour) const override 
		{ 
			Behaviour.UpdateLight(); 
		};
	};

protected:
	class BehaviourStrategies
	{
	public:
		static const StoppedBehaviour BehaviorStopped;
		static const NormalBehaviour BehaviorNormal;
	};

public:
	LightBehaviourCommand();

	/// Copy Constructor Deleted 
	/// 
	/// Copy Constructor Deleted Since Behaviours Are Meant To Exist On A Per-Light Basis
	LightBehaviourCommand(const LightBehaviourCommand& other) = delete;

	/// Assignment Operator Deleted 
	/// 
	/// Assignment Opera Deleted Since Behaviours Are Meant To Exist On A Per-Light Basis
	LightBehaviourCommand& operator=(const LightBehaviourCommand& other) = delete;

	/// Move Constructor Deleted 
	/// 
	/// Copy Constructor Deleted Since Behaviours Are Meant To Exist On A Per-Light Basis
	LightBehaviourCommand(LightBehaviourCommand&& other) = delete;

	/// Move Assignment Deleted 
	/// 
	/// Move Assignment Deleted Since Behaviours Are Meant To Exist On A Per-Light BasisLightBehaviourCommand& operator=(LightBehaviourCommand&& other) = delete;
	virtual ~LightBehaviourCommand() = default;

	/// Overridable Methods To Handle A Behaviours Startup and Shutdown Actions 
	virtual void StartBehaviour();
	virtual void StopBehaviour();

	/// Start The Behaviour By Actually Processing The Command
	/// 
	/// By default called whenever a light is first registered.
	/// 
	/// @note If you are overriding this class and want the behaviour to start being 
	/// processed again, you'll need to call this function.
	void StartProcessing();
	/// Stop The Behaviour By No Longer Processing The Command
	/// 
	/// By default called whenever a light is first deregistered.
	/// 
	/// @note If you are overriding this class and want the behaviour to stop being 
	/// processed altogether, you'll need to call this function.
	void StopProcessing();

private:
	/// Method called by LightManager to process behaviour updates
	void ProcessLight();

	/// Method Where Actual Update instructions are given
	virtual void UpdateLight() = 0;

	/// Callback functions for implemented Behaviour Commands to use
	/// 
	/// 
	/// ### Usage Example:
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// 
	/// // LightAlarm is a 
	/// class LightAlarm {
	/// 	// ...
	///		
	///		virtual void Alarm0() {
	///			Collidable::SetCollidableGroup<MyGameObject>();
	///			Collidable::SetBSphereModel(this->pModel);
	///		}
	/// 
	///		// ...
	/// };
	/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	virtual void Callback0() { }
	virtual void Callback1() { }
	virtual void Callback2() { }

protected:
	const BehaviourStrategy* currStrategy;
};

#endif // LIGHTBEHAVIOURCOMMAND_H
