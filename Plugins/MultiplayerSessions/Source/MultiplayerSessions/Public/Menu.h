// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"
class UButton;
class UMultiplayerSessionsSubsystem;

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")));

protected:
	virtual bool Initialize() override;

	// If we are travelling to another level, the current level will be drestroyed and remove.
	// In this case, all the widgets will call this function.
	virtual void NativeDestruct();
private:

	// UE Super is not working. Using this as a walkaround.
	using Super = UUserWidget;

	// This will links the widget in blueprint to the C++ varible.
	// Note that the name of the varible should be exactly the same as widget name.
	// If the engine did not find the widget with this name, it will crashes.
	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();

	UMultiplayerSessionsSubsystem* multiplayerSessionsSubsystem;

	int32 NumPublicConnections{4};
	FString MatchType{ TEXT("FreeForAll") };
};
