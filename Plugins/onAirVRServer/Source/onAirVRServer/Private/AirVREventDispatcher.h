/***********************************************************

  Copyright (c) 2017-2018 Clicked, Inc.

  Licensed under the MIT license found in the LICENSE file 
  in the Docs folder of the distributed package.

 ***********************************************************/

#pragma once

#include "JsonSerializer.h"

class IAirVREventListener
{
public:
    virtual void AirVREventSessionConnected(int PlayerID) {}
    virtual void AirVREventSessionDisconnected(int PlayerID) {}
    virtual void AirVREventPlayerCreated(int PlayerID) {}
    virtual void AirVREventPlayerActivated(int PlayerID) {}
    virtual void AirVREventPlayerDeactivated(int PlayerID) {}
    virtual void AirVREventPlayerDestroyed(int PlayerID) {}
    virtual void AirVREventPlayerShowCopyright(int PlayerID) {}
    virtual void AirVREventMediaStreamInitialized(int PlayerID) {}
    virtual void AirVREventMediaStreamStarted(int PlayerID) {}
    virtual void AirVREventMediaStreamEncodeVideoFrame(int PlayerID) {}
    virtual void AirVREventMediaStreamStopped(int PlayerID) {}
    virtual void AirVREventMediaStreamCleanedUp(int PlayerID) {}
    virtual void AirVREventInputStreamRemoteInputDeviceRegistered(int PlayerID, const FString& DeviceName, uint8 DeviceID) {}
    virtual void AirVREventInputStreamRemoteInputDeviceUnregistered(int PlayerID, uint8 DeviceID) {}
};

class FAirVREventDispatcher
{
public:
    void AddListener(IAirVREventListener* Listener);
    void RemoveListener(IAirVREventListener* Listener);
    void DispatchMessages();

private:
    void DispatchSessionMessage(int PlayerID, const TSharedPtr<FJsonObject>& Message);
    void DispatchPlayerMessage(int PlayerID, const TSharedPtr<FJsonObject>& Message);
    void DispatchMediaStreamMessage(int PlayerID, const TSharedPtr<FJsonObject>& Message);
    void DispatchInputStreamMessage(int PlayerID, const TSharedPtr<FJsonObject>& Message);
    
    void NotifySessionConnected(int PlayerID) const;
    void NotifySessionDisconnected(int PlayerID) const;
    void NotifyPlayerCreated(int PlayerID) const;
    void NotifyPlayerActivated(int PlayerID) const;
    void NotifyPlayerDeactivated(int PlayerID) const;
    void NotifyPlayerDestroyed(int PlayerID) const;
    void NotifyPlayerShowCopyright(int PlayerID) const;
    void NotifyMediaStreamInitialized(int PlayerID) const;
    void NotifyMediaStreamStarted(int PlayerID) const;
    void NotifyMediaStreamEncodeVideoFrame(int PlayerID) const;
    void NotifyMediaStreamStopped(int PlayerID) const;
    void NotifyMediaStreamCleanedUp(int PlayerID) const;
    void NotifyInputStreamRemoteInputDeviceRegistered(int PlayerID, const FString& DeviceName, uint8 DeviceID) const;
    void NotifyInputStreamRemoteInputDeviceUnregistered(int PlayerID, uint8 DeviceID) const;

private:
    TArray<IAirVREventListener*> Listeners;
};
