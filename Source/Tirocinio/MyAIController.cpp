#include "MyAIController.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h" // Inseriscilo qui per risolvere l'errore E0833
#include "HttpModule.h"

void AMyAIController::AskGemini(FString UserPrompt) {
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

    // URL di Gemini 1.5 Flash (sostituisci YOUR_API_KEY)
    Request->SetURL("https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=gen-lang-client-0295177077");
    Request->SetVerb("POST");
    Request->SetHeader("Content-Type", "application/json");

    // Creazione del corpo della richiesta JSON
    FString JsonPayload = FString::Printf(TEXT("{\"contents\": [{\"parts\":[{\"text\": \"%s\"}]}]}"), *UserPrompt);
    Request->SetContentAsString(JsonPayload);

    Request->OnProcessRequestComplete().BindUObject(this, &AMyAIController::OnGeminiResponseReceived);
    Request->ProcessRequest();
}

void AMyAIController::OnGeminiResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    if (bWasSuccessful && Response.IsValid()) {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

        if (FJsonSerializer::Deserialize(Reader, JsonObject)) {
            // Gemini risponde dentro: candidates[0].content.parts[0].text
            TArray<TSharedPtr<FJsonValue>> Candidates = JsonObject->GetArrayField("candidates");
            FString BotResponse = Candidates[0]->AsObject()->GetObjectField("content")->GetArrayField("parts")[0]->AsObject()->GetStringField("text");

            // Invia la risposta finale al Blueprint
            OnMessageReceived.Broadcast(BotResponse);
        }
    }
}