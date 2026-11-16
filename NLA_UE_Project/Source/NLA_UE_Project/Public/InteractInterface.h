#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

class NLA_UE_PROJECT_API IInteractInterface
{
	GENERATED_BODY()

public:
	// E ခလုတ် နှိပ်လိုက်သောအခါ ခေါ်မည်
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
	void Interact(AActor* Interactor);

	// မျက်နှာပြင်ပေါ်တွင် ပြမည့် စာသား ("Activate")
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
	FText GetInteractText() const;

	// Interact လုပ်လို့ရသော အခြေအနေ ဟုတ်/မဟုတ် (false ဆိုလျှင် မပြပါ)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
	bool CanInteract() const;
};