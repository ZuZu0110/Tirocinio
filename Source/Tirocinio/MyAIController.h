#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
class IHttpRequest;
class IHttpResponse;
#include "Interfaces/IHttpRequest.h"
#include "MyAIController.generated.h" // Deve essere l'ultimo include!



UCLASS() 
class TIROCINIO_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AI")
	void AskGemini(FString UserPrompt);

	UPROPERTY(BlueprintAssignable, Category = "AI")
	FOnMessageReceived OnMessageReceived;

private:
	// Usiamo FHttpRequestPtr e FHttpResponsePtr (non serve includere l'header qui)
	void OnGeminiResponseReceived(void* Request, void* Response, bool bWasSuccessful);
};