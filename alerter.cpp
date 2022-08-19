#include <iostream>
#include <assert.h>
using namespace std;

int alertFailureCount = 0;

float conversionFarenehitToCelcius(float temperatureInFarenehit)
{
    float temperatureInCelcius;
    temperatureInCelcius = (temperatureInFarenehit - 32) * 5 / 9;
    return(temperatureInCelcius);
}

int ProductionAlertStub(float celcius)
{
    cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Threshold needs to be defined for production environment, currently returning SUCCESS in all cases.
    return 200;
}
int NetworkAlertStub(float celcius)
{
    cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if (celcius > 200.0)
    {
        return 500;
    }
    else
    {
        return 200;
    }
}

void celciusAlert(const char* environment, float temperatureInFarenehit)
{
    int returnCode;
    string typeOfEnvironment = environment;
    float temperatureIncelcius = conversionFarenehitToCelcius(temperatureInFarenehit);

    if (typeOfEnvironment == "Production")
        returnCode = ProductionAlertStub(temperatureIncelcius);
    else if (typeOfEnvironment == "Test")
        returnCode = NetworkAlertStub(temperatureIncelcius);
    if (returnCode == 500)
    {
        alertFailureCount += 1;
    }
}

void numberOfFailures()
{
    assert(alertFailureCount == 1);
    cout << alertFailureCount << " alerts failed.\n";
}

int main() 
{
    celciusAlert("Test", 500);
    celciusAlert("Test", 500);
    celciusAlert("Production", 500);
    numberOfFailures();
    return 0;
}
