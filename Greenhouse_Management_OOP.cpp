#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 3 types of plant class which will be inherited by Plant class.

class Flowers
{
private:
    float price;
    int count;  //no. of plants available in greenhouse.

public: 
    Flowers()
    {
        price = 150.00;
        count = 0;
    }
    Flowers(int x)
    {
        count = x;
    }
    float getprice()
    {
        return price;
    }
    void addFlower()
    {
        count++;
    }
    void removeFlower()
    {
        count--;
    }

};

class Fruits
{
private:
    float price;
    int count;  //no. of plants available in greenhouse.

public:
    Fruits()
    {
        price = 200.00;
        count = 0;
    }
    Fruits(int x)
    {
        count = x;
    }
    float getprice()
    {
        return price;
    }
    void addFruit()
    {
        count++;
    }
    void removeFruit()
    {
        count--;
    }

};

class Vegetables 
{
private:
    float price;
    int count;  //no. of plants available in greenhouse.

public: 
    Vegetables() 
    {
        price = 175.00;
        count = 0;
    }
    Vegetables(int x)
    {
        count = x;
    }
    float getprice()
    {
        return price;
    }
    void addVegetable()
    {
        count++;
    }
    void removeVegetable()
    {
        count--;
    }

};
// All sensor classes used in the greenhouse.

class WateringSystem
{
    protected:
    int currentWaterLevel;
    int maxWaterLevel;
    int minWaterLevel;

    public:
    WateringSystem() {}
    WateringSystem(int water, int max, int min)
    {
        currentWaterLevel = water;
        maxWaterLevel = max;
        minWaterLevel = min;
    }
    void setwaterLevel(int water)
    {
        currentWaterLevel = water;
    }
    int getwaterLevel()
    {
        return currentWaterLevel;
    }
    void setmaxwater(int max)
    {
        maxWaterLevel = max;
    }
    int getmaxwater()
    {
        return maxWaterLevel;
    }
    void setminwater(int min)
    {
        minWaterLevel = min;
    }
    int getminwater()
    {
        return minWaterLevel;
    }
    void stopWater()
    {
        cout << "Sprinkler and channel blocked successfully, Water flow Stopped" << endl;
    }
    void waterPlants()
    {
        // Control amount and timing of watering based on soil moisture levels
        // drip irrigation is an effective and efficient method of delivering water and nutrients to plants
        cout << "Opening Sprinklers and Drip irrigation system to supply water to plants" << endl;
    }
    void checkWaterLevel()
    {
        if (currentWaterLevel >= minWaterLevel && currentWaterLevel <= maxWaterLevel)
        {
            cout << "WaterLevel is within the desired range." << endl;
        }
        else if (currentWaterLevel < minWaterLevel)
        {
            cout << "Warning: WaterLevel is too low!" << endl;
            waterPlants();
        }
        else
        {
            cout << "Warning: WaterLevel is too high!" << endl;
            stopWater();
        }
    }
};

class TemperatureSensor
{
    protected:
    double currentTemperature;
    double minTemperature;
    double maxTemperature;

    public:
    TemperatureSensor() {}
    TemperatureSensor(double T, double max, double min)
    {
        currentTemperature = T;
        minTemperature = max;
        maxTemperature = min;
    }
    void setcurrentTemperature(double current_temp)
    {
        currentTemperature = current_temp;
    }
    double getcurrentTemperature()
    {
        return currentTemperature;
    }
    void setMinTemperature(double min_temp)
    {
        minTemperature = min_temp;
    }
    double getMinTemperature()
    {
        return minTemperature;
    }
    void setMaxTemperature(double max_temp)
    {
        maxTemperature = max_temp;
    }
    double getMaxTemperature()
    {
        return maxTemperature;
    }
    void VentilationSystem()
    {
        cout << "VentilationSystem has been activated" << endl;
    }
    void HeatingSystem()
    {
        cout << "Heating System has been activated " << endl;
    }
    void checkTemperature()
    {
        if (currentTemperature >= minTemperature && currentTemperature <= maxTemperature)
        {
            cout << "Temperature is within the desired range." << endl;
        }
        else if (currentTemperature < minTemperature)
        {
            cout << "Warning: Temperature is too low!" << endl;
            HeatingSystem();
        }
        else
        {
            cout << "Warning: Temperature is too high!" << endl;
            VentilationSystem();
        }
    }
};

class HumiditySensor
{
    protected:
    TemperatureSensor t;
    WateringSystem w;
    double currenthumidity;
    double maxhumidity;
    double minhumidity;

    public:
    HumiditySensor()
    {
    }
    HumiditySensor(double h, double max, double min)
    {
        currenthumidity = h;
        maxhumidity = max;
        minhumidity = min;
    }
    void setcurrentHumidity(double h)
    {
        currenthumidity = h;
    }
    double getHumidity()
    {
        return currenthumidity;
    }
    void setmaxHumidity(double max)
    {
        maxhumidity = max;
    }
    double getmaxHumidity()
    {
        return maxhumidity;
    }
    void setminHumidity(double min)
    {
        minhumidity = min;
    }
    double getminHumidity()
    {
        return minhumidity;
    }
    void checkHumidity()
    {
        // Humidity can be increased by using humidifiers, misting systems, or by simply watering plants more frequently.
        // Ideal Value is 50-70%
        if (currenthumidity >= minhumidity && currenthumidity <= maxhumidity)
        {
            cout << "Humidity is within the desired range." << endl;
        }
        else if (currenthumidity < minhumidity)
        {
            cout << "Warning! Humidity Levels are low and can cause stunned growth" << endl;
            w.waterPlants();
        }
        else
        {
            cout << "Warning! Humidity Levels are high due to insufficient air movement" << endl;
            t.VentilationSystem();
        }
    }
};

class CO2Sensor
{
    protected:
    // CO2 level should be around : 800-1200 ppm (parts per million)
    TemperatureSensor t;
    int maxCO2;
    int minCO2;
    int currentCO2;

    public:
    CO2Sensor() {}
    CO2Sensor(int max, int min, int x)
    {
        minCO2 = max;
        maxCO2 = min;
        currentCO2 = x;
    }
    void setMinCO2(int min_CO2)
    {
        minCO2 = min_CO2;
    }
    int getMinCO2()
    {
        return minCO2;
    }
    void setMaxCO2(int max_CO2)
    {
        maxCO2 = max_CO2;
    }
    int getMaxCO2()
    {
        return maxCO2;
    }
    void setcurrentCO2(int current_CO2)
    {
        currentCO2 = current_CO2;
    }
    int getcurrentCO2()
    {
        return currentCO2;
    }
    void CO2Generators()
    {
        cout << "CO2 generation has been started ..." << endl;
    }
    void checkCO2()
    {
        if (currentCO2 >= minCO2 && currentCO2 <= maxCO2)
        {
            cout << "CO2 is within the desired range." << endl;
        }
        else if (currentCO2 < minCO2)
        {
            cout << "Warning: CO2 is too low!" << endl;
            CO2Generators();
        }
        else
        {
            cout << "Warning: CO2 is too high!" << endl;
            t.VentilationSystem();
        }
    }
};

class PHSensor
{
    protected:
    // pH level: 6.0-6.5 for most plants, although some plants may require different pH levels
    float maxPH;
    float minPH;
    float currentPH;

    public:
    PHSensor() {}
    PHSensor(float x, float max, float min)
    {
        minPH = max;
        maxPH = min;
        currentPH = x;
    }
    void setMinPH(float min_PH)
    {
        minPH = min_PH;
    }
    float getMinPH()
    {
        return minPH;
    }
    void setMaxPH(float max_PH)
    {
        maxPH = max_PH;
    }
    float getMaxPH()
    {
        return maxPH;
    }
    void setcurrentPH(float current_PH)
    {
        currentPH = current_PH;
    }
    float getcurrentPH()
    {
        return currentPH;
    }
    void addLimeandAsh()
    {
        cout << "Lime and Ash have been added to the soil" << endl;
    }
    void addSulfurandSulfates()
    {
        cout << "Sulfur and sulfates have been added to the soil" << endl;
    }
    void checkPH()
    {
        if (currentPH >= minPH && currentPH <= maxPH)
        {
            cout << "PH is within the desired range." << endl;
        }
        else if (currentPH < minPH)
        {
            cout << "Warning: PH is too low!" << endl;
            cout << "apply materials such as lime or wood ash to raise the pH" << endl;
            addLimeandAsh();
        }
        else
        {
            cout << "Warning: PH is too high!" << endl;
            cout << "apply materials such as sulfur, aluminum sulfate, or iron sulfate to lower the pH" << endl;
            addSulfurandSulfates();
        }
    }
};

class SoilMoistureSensor
{
    protected:
    // Soil moisture level: 50-70% of soil water holding capacity, depending on the plant species and growth stage
    int maxSoilMoisture;
    int minSoilMoisture;
    int currentSoilMoisture;
    WateringSystem w;

    public:
    SoilMoistureSensor() {}
    SoilMoistureSensor(int s, int max, int min)
    {
        minSoilMoisture = max;
        maxSoilMoisture = min;
        currentSoilMoisture = s;
    }
    void setcurrentSoilMoisture(int current_SoilMoisture)
    {
        currentSoilMoisture = current_SoilMoisture;
    }
    int getcurrentSoilMoisture()
    {
        return currentSoilMoisture;
    }
    void setMinSoilMoisture(int min_SoilMoisture)
    {
        minSoilMoisture = min_SoilMoisture;
    }
    int getMinSoilMoisture()
    {
        return minSoilMoisture;
    }
    void setMaxSoilMoisture(int max_SoilMoisture)
    {
        maxSoilMoisture = max_SoilMoisture;
    }
    int getMaxSoilMoisture()
    {
        return maxSoilMoisture;
    }
    void checkSoilMoisture()
    {
        if (currentSoilMoisture >= minSoilMoisture && currentSoilMoisture <= maxSoilMoisture)
        {
            cout << "SoilMoisture is within the desired range." << endl;
        }
        else if (currentSoilMoisture < minSoilMoisture)
        {
            cout << "Warning: SoilMoisture is too low!" << endl;
            cout << "need to increase irrigation or apply much to help retain moisture in the soil." << endl;
            w.waterPlants();
        }
        else
        {
            cout << "Warning: SoilMoisture is too high!" << endl;
            cout << "Adjust irrigation practices by reducing the amount of watering" << endl;
            w.stopWater();
        }
    }
};

class LightSensor
{
    protected:
    // provide 1000-1500 micromoles of
    // photosynthetically active radiation (PAR) per square meter per second
    int currentLightLevel;
    int maxLightLevel;
    int minLightLevel;

    public:
    LightSensor() {}
    LightSensor(int l, int max, int min)
    {
        currentLightLevel = l;
        maxLightLevel = max;
        minLightLevel = min;
    }
    void setcurrentLightLevel(int light)
    {
        currentLightLevel = light;
    }
    double getcurrentLightLevel()
    {
        return currentLightLevel;
    }
    void setmaxLight(int max)
    {
        maxLightLevel = max;
    }
    double getmaxLight()
    {
        return maxLightLevel;
    }
    void setminLight(int min)
    {
        minLightLevel = min;
    }
    double getminLight()
    {
        return minLightLevel;
    }
    void increaseShade()
    {
        cout << "Increasing shading by lowering the shade cloth or adding more layers of shade cloth.\n";
    }
    void decreaseShade()
    {
        cout << "Decreasing shading by raising the shade cloth or removing layers of shade cloth.\n";
    }
    void ArtificialLight(string choice)
    {
        if (choice == "YES")
        {
            cout << "Lights are ON" << endl;
        }
        else
        {
            cout << "Lights are OFF" << endl;
        }
    }

    void checkLightLevel()
    {
        if (currentLightLevel >= minLightLevel && currentLightLevel <= maxLightLevel)
        {
            cout << "Light levels optimal. No shading adjustment needed." << endl;
        }
        else if (currentLightLevel > maxLightLevel)
        {
            cout << "Light levels too high. Increasing shading." << endl;
            increaseShade();
            ArtificialLight("NO");
        }
        else
        {
            cout << "Light levels too low. Decreasing shading." << endl;
            decreaseShade();
            ArtificialLight("YES");
        }
    }
};

class Fertilizer
{
    int nitrogen;
    int phosphorus;
    int potassium;
    static int quantity;

public:
    // Constructor
    Fertilizer() {}
    Fertilizer(int nLevel, int pLevel, int kLevel)
    {
        nitrogen = nLevel;
        phosphorus = pLevel;
        potassium = kLevel;
    }

    // Getter functions for each nutrient level
    int getNitrogenLevel()
    {
        return nitrogen;
    }
    int getPhosphorusLevel()
    {
        return phosphorus;
    }
    int getPotassiumLevel()
    {
        return potassium;
    }
    int getQuantity()
    {
        return quantity;
    }
    // Function to add more quantity of the fertilizer
    void addQuantity()
    {
        int q;
        cout << "Enter the amount of fertilizer you want to add in stock (in grams): ";
        cin >> q;
        quantity += q;
    }
    void removeQuantity(int q)
    {
        quantity -= q;
    }
    void addNitrogen(double amount, double soilVolume)
     {
        double nitrogenConcentration = 0.05;
        double nitrogenToAdd = amount * nitrogenConcentration * soilVolume;
        cout << "Amount of "<< nitrogenToAdd << " Nitrogen added to soil" << endl;
    }
    void addPhosphorus(double amount, double soilVolume)
    {
        double PhosphorusConcentration = 0.10;
        double PhosphorusToAdd = amount * PhosphorusConcentration * soilVolume;
        cout << "Amount of "<< PhosphorusToAdd << " Phosphorus added to soil" << endl;
    }
    void addPotassium(double amount, double soilVolume)
    {
        double PotassiumConcentration = 0.02;
        double PotassiumToAdd = amount * PotassiumConcentration * soilVolume;
        cout << "Amount of "<< PotassiumToAdd << " Potassium added to soil" << endl;
    }

    // Function to check if the nutrient levels are below a certain threshold
    bool isLowOnNutrients(int nThreshold, int pThreshold, int kThreshold)
    {
        return (nitrogen < nThreshold || phosphorus < pThreshold || potassium < kThreshold);
    }
};
int Fertilizer::quantity = 100;

// Main PLANT class which has all sensor classes as its member.

class Plant : public Flowers, public Fruits, public Vegetables
{
private:
    string name;
    string type;
	
	WateringSystem* water;
    TemperatureSensor* temperature;
    HumiditySensor* humidity;
    CO2Sensor* co2;
    PHSensor* ph;
    SoilMoistureSensor* soilmoisture;
	LightSensor* light;
	Fertilizer* fertilizer;
	    
public:
    Plant()
    {
        name = "Null";
        type = "Null";
    	water =  new WateringSystem(60,70,50);    
		temperature = new TemperatureSensor(25.0,30.0,18.0);
        humidity = new HumiditySensor(60.0,50.0,70.0);
        co2 = new CO2Sensor(1200,800,1000);
    	ph = new PHSensor(6.2,7.0,5.5);
    	soilmoisture = new SoilMoistureSensor(60,70,50);
		light = new LightSensor(1200,1500,1000);
        fertilizer = new Fertilizer(10,5,5);
        
    }
    
    void setName(string name)
    {
        this->name = name;
    }
    
    void settype(string type)
    {
        this->type = type;
    }
    
    string getName()
    {
        return name;
    }
    
    string gettype()
    {
        return type;
    }

    void presetvalues() {
        double maxtemp = temperature->getMaxTemperature();
        double mintemp = temperature->getMinTemperature();
        double maxhumid = humidity->getmaxHumidity();
        double minhumid = humidity->getminHumidity();
        double maxlight = light->getmaxLight();
        double minlight = light->getminLight();
        int maxwater = water->getmaxwater();
        int minwater = water->getminwater();
        int maxco2 = co2->getMaxCO2();
        int minco2 = co2->getMinCO2();
        float maxph = ph->getMaxPH();
        float minph = ph->getMinPH();
        int maxsoil = soilmoisture->getMaxSoilMoisture();
        int minsoil = soilmoisture->getMinSoilMoisture();
        int nitrogen = fertilizer->getNitrogenLevel();
        int phosphorus = fertilizer->getPhosphorusLevel();
        int potassium = fertilizer->getPotassiumLevel();

        cout << "Sensors requirement for all the plants:" << endl;
        cout << "---------------------------------- " << endl;
        cout << "Maximum Temperature : " << maxtemp << " degree celcius" << endl;
        cout << "Minimum Temperature : " << mintemp << " degree celcius" << endl << endl;
        cout << "Maximum Humidity    : " << maxhumid << "%" << endl;
        cout << "Minimum Humidity    : " << minhumid << "%" << endl << endl;
        cout << "Max Light Intensity : " << maxlight << " micromoles" << endl;
        cout << "Min Light Intensity : " << minlight << " micromoles" << endl << endl;
        cout << "Maximum Water level : " << maxwater << "%" << endl;
        cout << "Minimum Water level : " << minwater << "%" << endl << endl;
        cout << "Maximum CO2 level   : " << maxco2 << " ppm" << endl;
        cout << "Minimum CO2 level   : " << minco2 << " ppm" << endl << endl;
        cout << "Maximum PH level    : " << maxph << " pH" << endl;
        cout << "Minimum PH level    : " << minph << " pH" << endl << endl;
        cout << "Maximum Soil level  : " << maxsoil << "%" << endl;
        cout << "Minimum Soil level  : " << minsoil << "%" << endl << endl;
        cout << "FERTILIZERS:-" << endl;
        cout << "Nitrogen level      : " << nitrogen << " grams" << endl;
        cout << "Phosphorus level    : " << phosphorus << " grams" << endl;
        cout << "Potassium level     : " << potassium << "grams" << endl;
    }
    
    void setCurrentValues()
    {
            int wlvl,clvl,slvl,lilvl;
            double tlvl,hlvl,phlvl;
            cout << endl;
            cout<<"Enter Current Value Of Water sensor: ";
            cin>>wlvl;
            water->setwaterLevel(wlvl);
            cout<<"Enter Current Value Of Temperature sensor: ";
            cin>>tlvl;
            temperature->setcurrentTemperature(tlvl);
            cout<<"Enter Current Value Of Humidity sensor: ";
            cin>>hlvl;
            humidity->setcurrentHumidity(hlvl);
            cout<<"Enter Current Value Of CO2 sensor: ";
            cin>>clvl;
            co2->setcurrentCO2(clvl);
            cout<<"Enter Current Value Of PH sensor: ";
            cin>>phlvl;
            ph->setcurrentPH(phlvl);
            cout<<"Enter Current Value Of Soil Moisture sensor: ";
            cin>>slvl;
            soilmoisture->setcurrentSoilMoisture(slvl);
            cout<<"Enter Current Value Of Light sensor: ";
            cin>>lilvl; 
            light->setcurrentLightLevel(lilvl);
            cout<<endl<<endl;
            cout<<"ALL CURRENT VALUES OF SENSORS HAVE BEEN SUCCESSFULLY UPDATED!!!"<<endl;
            
    }

    void displaycurrentvalues() 
    {    
        cout << " _____________________________________ " << endl;
        cout << "|                                     |" << endl;
        cout << "| Sensors         | Values            |" << endl;
        cout << " ------------------------------------- " << endl;
        cout << "| Temperature     | " << temperature->getcurrentTemperature() << " degree celcius |" << endl;
        cout << "| Humidity        | " << humidity->getHumidity() << "%               |" << endl;
        cout << "| Light Intensity | " << light->getcurrentLightLevel() << " micromoles   |" << endl;
        cout << "| Water level     | " << water->getwaterLevel() << "%               |" << endl;
        cout << "| CO2 level       | " << co2->getcurrentCO2() << " ppm          |" << endl;
        cout << "| PH level        | " << ph->getcurrentPH() << " pH            |" << endl;
        cout << "| Soil level      | " << soilmoisture->getcurrentSoilMoisture() << "%               |" << endl;
        cout << " _____________________________________ " << endl;
        
//      cout << "FERTILIZERS:-" << endl;
//      cout << "Nitrogen level    : " << fertilizer->getNitrogenLevel() << " grams" << endl;
//      cout << "Phosphorus level  : " << fertilizer->getPhosphorusLevel() << " grams" << endl;
//      cout << "Potassium level   : " << fertilizer->getPotassiumLevel() << "grams" << endl;
    }

    void callSensorrChecks()
    {
        int opt;
        do
        {
            cout << "Which sensor you want to check: " << endl;
            cout << "1. Water sensor" << endl;
            cout << "2. Temperature sensor" << endl;
            cout << "3. Humidity sensor" << endl;
            cout << "4. CO2 sensor" << endl;
            cout << "5. PH sensor" << endl;
            cout << "6. Soil moisture sensor" << endl;
            cout << "7. Light sensor" << endl;
            cout << "0. Go back!" << endl;
            cout << endl << "Choose your option: ";
            cin >> opt;
            switch (opt)
            {
                case 1:
                    water->checkWaterLevel();
                break;
                
                case 2:    
                    temperature->checkTemperature();
                break;

                case 3:    
                    humidity->checkHumidity();
                break;

                case 4:    
                    co2->checkCO2();
                break;

                case 5:    
                    ph->checkPH();
                break;

                case 6:    
                    soilmoisture->checkSoilMoisture();
                break;

                case 7:    
                    light->checkLightLevel();
                break;

                case 0:    
                    cout << "Going back....";
                break;

                default:
                    cout << "Invalid option!" << endl;    
            }
            cout << endl;
            system("pause");
            cout << endl;

        } while (opt != 0);
    }

    ~Plant() {
        delete water;    
		delete temperature;
        delete humidity;
        delete co2;
    	delete ph;
    	delete soilmoisture;
		delete light;
    	delete fertilizer;
	}
    
};

// Main GREENHOUSE class

class Greenhouse
{
private:
    int capacity;  // no. of plants that can fit in greenhouse.
    int count;     // no. of plants available in greenhouse.

public:
    Plant plants[100];

    Greenhouse()
    {
        capacity = 50;

        plants[0].setName("Lilly");
        plants[0].settype("Flower");
        plants[0].addFlower();
        
        plants[1].setName("Mango");
        plants[1].settype("Fruit");
        plants[1].addFruit();
        
        plants[2].setName("Eggplant");
        plants[2].settype("Vegetable");
        plants[2].addVegetable();
        
        plants[3].setName("Rose");
        plants[3].settype("Flower");
        plants[3].addFlower();
        
        plants[4].setName("Banana");
        plants[4].settype("Fruit");
        plants[4].addFruit();
        
        plants[5].setName("Lettuce");
        plants[5].settype("Vegetable");
        plants[5].addVegetable();
        
        plants[6].setName("Daisy");
        plants[6].settype("Flower");
        plants[6].addFlower();
        
        plants[7].setName("Apple");
        plants[7].settype("Fruit");
        plants[7].addFruit();
        
        plants[8].setName("Spinach");
        plants[8].settype("Vegetable");
        plants[8].addVegetable();
        
        plants[9].setName("Orange");
        plants[9].settype("Fruit");
        plants[9].addFruit();
        
        count = 10;
    }
    int getcount()
    {
        return count;
    }

    Plant getplants(int i) const 
    {
        return plants[i];
    }

    void addPlant()
    {
        if (count >= capacity)
        {
            cout << "There is no capacity in the greenhouse.";
        }
        else
        {
            int option;
            string name;

            cout << "Enter the name of the plant: ";
            cin >> name;
            cout << endl << "These are the three types of Plants:" << endl;
            cout << "1. Flower   2. Fruit   3. Vegetable" << endl;
            cout << endl << "Choose your option: ";
            cin >> option;

                switch(option)
                {
                    case 1: 
                            plants[count].setName(name);
                            plants[count].settype("Flower");
                            plants[count].addFlower();
                            count++;
                    break;
                    case 2:
                            plants[count].setName(name);
                            plants[count].settype("Fruit");
                            plants[count].addFruit();
                            count++;
                    break;        
                    case 3:
                            plants[count].setName(name);
                            plants[count].settype("Vegetable");
                            plants[count].addVegetable();
                            count++;
                    break;
                    default:
                    		cout << "Invalid option!" << endl;
                }
            
        }
        
    }

    void removePlant(int index)
    {
        plants[index].setName("Null");
        string type = plants[index].gettype();
        
        if (type == "Flower"){
            for (int i = index; i < count - 1; ++i) {
        		plants[i] = plants[i + 1];
		    }
            plants[index].removeFlower();                       
        }
        else if (type == "Fruit"){
            for (int i = index; i < count - 1; ++i) {
        		plants[i] = plants[i + 1];
		    }
			plants[index].removeFruit();
        }
        else if (type == "Vegetable"){
            for (int i = index; i < count - 1; ++i) {
        		plants[i] = plants[i + 1];
		    }
			plants[index].removeVegetable();
        }
        count--;
    }
    
    void Plantdatabase()
	{
        cout << "_______________________________________" << endl;
        cout << "   Index     Name         Type" << endl;
        cout << "_______________________________________" << endl;
        for (int i=0; i<count; i++)
        {
            cout << "     " << i;
            cout << "      " << plants[i].getName();
            cout << "        " << plants[i].gettype() << endl;
            cout << "---------------------------------------" << endl;
        }
	}
};

class Seeds
{
private:
    static int flower;     // no. of flower seeds
    static int fruit;      // no. of fruit seeds
    static int vegetable;  // no. of vegetable seeds

public:
    static int getflower()
    {
        return flower;
    }

    static int getfruit()
    {
        return fruit;
    }

    static int getvegetable()
    {
        return vegetable;
    }

    void removeFlowerSeed(int x)
    {
        flower = flower - x;    
    }
    
    void removeFruitSeed(int x)
    {
        fruit = fruit - x;    
    }
    
    void removeVegetableSeed(int x)
    {
        vegetable = vegetable - x;    
    }
    
    void addSeeds()
    {
        int x,y,z;

        cout << "How many flower seeds you want to add in stock: ";
        cin >> x;
        cout << "How many fruit seeds you want to add in stock: ";
        cin >> y;
        cout << "How many vegetable seeds you want to add in stock: ";
        cin >> z;
        
        flower = flower + x;    
        fruit = fruit + y;    
        vegetable = vegetable + z;        
    }
};
// static values
int Seeds::flower = 100;
int Seeds::fruit = 100;
int Seeds::vegetable = 100;

// Now all the classes will be costumer related:-

class CustomerInfo
{
    private:
    string name;
    string phnum;
    string address;
    float moneyspent;

    public:
    CustomerInfo()
    {
        name = "";
        phnum = "";
        address = "";
        moneyspent = 0;
    }
    
    CustomerInfo(string n, string p, string a)
    {
        name = n;
        phnum = p;
        address = a;
        moneyspent = 0;
    }
    
    void setname(string x)
    {
        name = x;
    }
    
    void setnumber(string n)
    {
        phnum = n;
    }
    
    void setaddress(string a)
    {
        address = a;
    }
    
    string getname()
    {
        return name;
    }
    
    string getnum()
    {
        return phnum;
    }
    
    string getaddress()
    {
        return address;
    }
    
    void addmoney(float x)
    {
        moneyspent += x;
    }

    void printInfo()
    {
        cout << "Name    : " << name << endl;
        cout << "Phone   : " << phnum << endl;
        cout << "Address : " << address << endl;
        cout << "Amount  : " << moneyspent << endl;
    }
};

class Workers
{
    private:
    string name;
    string phnum;
    char gender;
    bool isFree;

    public:
    Workers()
    {
        name = "";
        phnum = "";
        gender = 'N';
        isFree = true;
    }

    Workers(string n, string p, char g)
    {
        name = n;
        phnum = p;
        gender = g;
        isFree = true;
    }

    void setname(string x)
    {
        name = x;
    }

    void setnumber(string n)
    {
        phnum = n;
    }

    void setgender(char g)
    {
        gender = g;
    }

    string getname()
    {
        return name;
    }

    string getnum()
    {
        return phnum;
    }

    char getgender()
    {
        return gender;
    }

    void freeworker()
    {
        isFree = true;
    }

    void occupied()
    {
        isFree = false;
    }

    bool checkworker()
    {
        return isFree;
    }
};

class WorkersDatabase 
{
    private: 
    
    int n;

    public:
    Workers worker[20];
	WorkersDatabase()
    {
        worker[0].setname("Hamza");
        worker[0].setnumber("03002456789");
        worker[0].setgender('M');
        worker[0].freeworker();

        worker[1].setname("Faiza");
        worker[1].setnumber("03343662848");
        worker[1].setgender('F');
        worker[1].freeworker();

        n = 2;
    }

    int getcount()
    {
        return n;
    }

    void Addworkers()
    {
        string name, phone;
        char gen;

        cout << "Enter worker's name: ";
        cin >> name;
        cout << "Enter his/her phone number: ";
        cin >> phone;
        cout << "Enter his/her gender ('M'/'F'): ";
        cin >> gen;

        worker[n].setname(name);
        worker[n].setnumber(phone);
        worker[n].setgender(gen);
        worker[n].freeworker();
        n++;
    }

    void displayWorkers()
    {
        cout << "_______________________________________________________________" << endl;
        cout << "WorkerID    " 
             << "Name         "
             << "Number           "
             << "Gender    "
             << "Available  " << endl;
        cout << "_______________________________________________________________" << endl;     

        for (int i = 0; i <= n - 1; i++)
        {
            cout << "   " << i << "        ";
            cout << worker[i].getname() << "        ";
            cout << worker[i].getnum() << "         ";
            cout << worker[i].getgender() << "      ";
            if (worker[i].checkworker() == true)
            {
                cout << "   " << "YES" << endl;
            }
            else{
                cout << "   " << "NO" << endl;
            }
            cout << "---------------------------------------------------------------" << endl;
        }
    }
};

class Installation : public WorkersDatabase
{
    private:
    string address;

    public:
    Installation()
    {
        address = "";
    }

    Installation(string x)
    {
        address = x;
    }

    int Installplant(int index)
    {
        char opt;
        if(worker[index].checkworker() == true)
        {
            cout << "The cost for installation of plant is 15 dollars." << endl;
            cout << "Do you want to install plant ('Y' or 'N'): ";
            cin >> opt;

            if (opt == 'y' || opt == 'Y')
            {
                worker[index].occupied();
                cout << worker[index].getname() << " will install the plant at " << address << endl;
                return 15;
            }
            else
            {
                cout << "installation cancelled!" << endl;
                return 0;
            }
        }
        else
        {
            cout << "This worker is not available." << endl;
            return 0;
        }
    }

};

class Appointment : public WorkersDatabase
{
    private:
    string address;

    public:
    Appointment()
    {
        address = "";
    }
    Appointment(string a)
    {
        address = a;
    }

    int BookAppointment(int ind)
    {
        char ch;
        if(worker[ind].checkworker() == true)
        {
            cout << worker[ind].getname() << " is available " << endl;
            cout << "The appointment costs 30 dollars." << endl << endl;
            cout << "Do you want to book an appointment ('Y' or 'N'): " ;
            cin >> ch;
            cout << endl;
            if (ch == 'y' || ch == 'Y')
            {
                worker[ind].occupied();
                cout << "Appointment successfully booked" << endl;
                cout << worker[ind].getname() << " is appointed for 03:00 at your provided address." << endl;
                return 30;
            }
        }
        else
        {
            cout << "This worker is not available." << endl;
            return 0;
        }
    }
};

class BuyPlant
{
public:
    float purchasePlant(Greenhouse *ptr)
    {
        int x,y;
        ptr->Plantdatabase();
        cout << endl;
        cout << "Enter the index of plant you want to purchase: ";
        cin >> x;
        y = ptr->getcount(); 
        if (x < y && x >= 0)
		{
	        Plant plants = ptr->getplants(x);
	        string type = plants.gettype();
	        
	        float price;
	        if (type == "Flower"){
	            price = plants.Flowers::getprice();        
	        }else if (type == "Fruit"){
	            price = plants.Fruits::getprice();
	        }else if (type == "Vegetable"){
	            price = plants.Vegetables::getprice();
	        }
	
	        char ch;
	        cout << "The price is: " << price << endl;
	        cout << "Do you want to purchase ('Y' or 'N'): ";
	        cin >> ch;
	        if (ch == 'y' || ch == 'Y')
	        {
	            cout << "Purchase successful" << endl;
	            ptr->removePlant(x);
	            return price;
	        }
	        else
	        {
	            cout << "Purchase declined" << endl;
	            return 0;
	        }
		}
		else {
			cout << "Invalid index!" << endl;
			return 0;
		}
    }
};

class BuySeed
{
    public:
    int purchaseSeed(Seeds *ptr)
    {
        int x;
        int type;

        cout << "The three types of seeds are:" << endl;
        cout << "1. Flower   2. Fruit   3. Vegetable" << endl << endl;
        cout << "Enter the type of seed you want to purchase: ";
        cin >> type;
       	cout << "The price is 1 dollars each." << endl;
        cout << "How many seeds do you want: ";              
        cin >> x;

            switch (type)
            {
                case 1:
                        if (ptr->getflower() >= x)
                        {
                            ptr->removeFlowerSeed(x);
                            cout << "Purchase Successful!" << endl;
                            return x;
                        }
                        else {
                            cout << "Seeds are not available right now." << endl;
                            cout << "Try again later." << endl;
                            return 0;
                        }
                break;
                case 2:
                        if (ptr->getfruit() >= x)
                        {
                            ptr->removeFruitSeed(x);
                            cout << "Purchase Successful!" << endl;
                            return x;
                        }
                        else {
                            cout << "Seeds are not available right now." << endl;
                            cout << "Try again later." << endl;
                            return 0;
                        }
                break;
                case 3:
                        if (ptr->getvegetable() >= x)
                        {
                            ptr->removeVegetableSeed(x);
                            cout << "Purchase Successful!" << endl;
                            return x;
                        }
                        else {
                            cout << "Seeds are not available right now." << endl;
                            cout << "Try again later." << endl;
                            return 0;
                        }
                break;
                default: 
                		cout << "Invalid option!" << endl;
            			return 0;
            			
            }
    }
};

class BuyFertilizer
{
    public:
    int purchaseFert(Fertilizer *ptr)
    {
        int x;

        cout << "The price of 1 gram of fertilizer is 2 dollars." << endl;
        cout << "How many grams do you want: ";              
        cin >> x;

        if (ptr->getQuantity() >= x)
        {
            ptr->removeQuantity(x);
            cout << "Purchase Successful!" << endl;
            int p = x * 2;
            return p;
        }
        else {
            cout << "Fertilizer is not available right now." << endl;
            cout << "Try again later." << endl;
            return 0;
        }
        
    }
};

int main()
{
    Greenhouse G;
    Seeds seed;
    Fertilizer fert;
    WorkersDatabase W;
    CustomerInfo info;
	int ch, option;
    string name, num, address;
    int worker_count=2,plant_counter=10;

    do 
	{
    cout << endl;    
    cout << "                         WELCOME TO THE SUB BEMIRE !!!" << endl;
    cout << "                        'Don't be mean, just go green'" << endl << endl;
    cout << "   _________________________________________________________________________ " << endl;
    cout << "  | Press 1  | Would you like to continue as a manager at The Sub Bemire !  |" << endl;
    cout << "  | press 2  | Would you like to continue as a costumer at The Sub Bemire ! |" << endl;
    cout << "  | press 0  | Exit the program !                                           |" << endl;
    cout << "  |_________________________________________________________________________|" << endl;
    cout << endl << "  Choose your option: ";
    cin >> option;

    switch(option){
        case 1:
            system("cls");
            cout << endl << "Welcome Master, what do you want to do into your GreenHouse?" << endl << endl;
            do
            {
                cout << endl;
                cout << " _________________________________________________ " << endl;
                cout << "| 1 | Add a Plant in our greenhouse               |" << endl;
                cout << "| 2 | Display Plants database                     |" << endl;
                cout << "| 3 | Add more Seeds in the stock                 |" << endl;
                cout << "| 4 | Add more fertilizers in the stock           |" << endl;
                cout << "| 5 | Add a worker in our greenhouse              |" << endl;
                cout << "| 6 | Display workers database                    |" << endl;
                cout << "| 7 | Display Preset sensor values                |" << endl;
                cout << "| 8 | Display/Set sensor values of specific plant |" << endl;
                cout << "| 9 | Check sensor values of specific plant       |" << endl;
                cout << "| 0 | Go back!                                    |" << endl;
                cout << "|_________________________________________________|" << endl;
                
                cout << endl << "Enter your choice: ";
                cin>>ch;
                if(ch==1)
                {
                    cout << endl;
                    G.addPlant();
                    plant_counter++;
                    system("pause");
                    system("cls");
                }
                else if(ch==2)
                {
                    cout << endl;
                    G.Plantdatabase();
                    system("pause");
                    system("cls");
                }
                else if(ch==3)
                {
                    cout << endl;
                    seed.addSeeds();
                    system("pause");
                    system("cls");
                }
                else if(ch==4)
                {
                    cout << endl;
                    fert.addQuantity();
                    system("pause");
                    system("cls");
                }
                else if(ch==5)
                {
                    cout << endl;
                    W.Addworkers(); 
                    worker_count++;
                    system("pause");
                    system("cls");
                }
                else if(ch==6)
                {
                    cout << endl;
                    W.displayWorkers();
                    system("pause");
                    system("cls");
                }
                else if(ch==7)
                {
                    cout << endl;
                    Plant P;
                    P.presetvalues();	  
                    system("pause");
                    system("cls");
                }
                else if(ch==8) 
                {
                    cout << endl;
                    int indi,c;
                    G.Plantdatabase();
                    cout << endl << "Choose a Plant! Enter the index number: ";
                    cin >> indi; 
                    system("cls");
                    do 
                    {
                        cout << "1. Display sensor values" << endl;
                        cout << "2. Set sensor values" << endl;
                        cout << "0. Go back!" << endl;
                        cout << endl << "Choose your option: ";
                        cin >> c; 
        
                        switch (c)
                        {
                            case 1:    
                                G.plants[indi].displaycurrentvalues();	  
                            break;

                            case 2:
                                G.plants[indi].displaycurrentvalues();
                                G.plants[indi].setCurrentValues();	  
                            break;

                            case 0:    
                                cout << "Going back..." << endl;
                                	  
                            break;

                            default:
                                cout << "Invalid option!" << endl;
                        }
                        system("pause");
                        system("cls");
                    } while (c!=0);
                    
                    system("cls");
                }
                else if(ch==9)
                {
                    cout << endl;
                    int in;
                    G.Plantdatabase();
                    cout << endl << "Choose a Plant! Enter the index number: ";
                    cin >> in; 
                    G.plants[in].callSensorrChecks();	  
                    system("cls");
                }
                else if(ch==0)
                {
                    cout << "Going back...." << endl;
                    system("pause");
                    system("cls");
                }
                else {
                    cout << endl << "Invalid option!" << endl;
                }
            } while(ch!=0);
        break;

        case 2:
        	cout << endl;
            cout << "  Please Enter your name: ";
            fflush(stdin);
			getline(cin, name);
            info.setname(name);
            cout << "  Please Enter your phone number: ";
            cin >> num;
            info.setnumber(num);
            cout << "  Please Enter your address: ";
            fflush(stdin);
			getline(cin, address);
            info.setaddress(address);
			
			system("cls");

            cout << endl << "Welcome "<<name<<" , you have been registered with our GreenHouse Nursery!"<<endl;
            do
            {
                cout << endl;
                cout << " _____________________________________________________ " << endl;
                cout << "| We offer the following services for our customers:  |" << endl;
                cout << "|-----------------------------------------------------|" << endl;
                cout << "| 1  | Buy a Plant                                    |" << endl;
                cout << "| 2  | Buy a Seed                                     |" << endl;
                cout << "| 3  | Buy a Fertilizer                               |" << endl;
                cout << "| 4  | Install a plant                                |" << endl;
                cout << "| 5  | Book an appointment                            |" << endl;
                cout << "| 6  | View customer information                      |" << endl;
                cout << "| 0  | Go back!                                       |" << endl;
                cout << "|_____________________________________________________|" << endl;

                cout << endl << "Enter your choice: ";
                cin>>ch;
                if(ch==1)
                {
                    cout << endl;
                    BuyPlant obj;
                    float p = obj.purchasePlant(&G);
                    info.addmoney(p);
                    system("pause");
                    system("cls");
                }
                else if(ch==2)
                {
                    cout << endl;
                    BuySeed obj1;
                    float p1 = obj1.purchaseSeed(&seed);
                    info.addmoney(p1);
                    system("pause");
                    system("cls");
                }
                else if(ch==3)
                {
                    cout << endl;
                    BuyFertilizer obj2;
                    float p2 = obj2.purchaseFert(&fert);
                    info.addmoney(p2);
                    system("pause");
                    system("cls");
                }
                else if(ch==4)
                {
                    int x;
                    cout << endl;
                    W.displayWorkers();
                    cout << endl << "Enter valid worker ID: ";
                    cin >> x;
                    int z = W.getcount();
					if (x<z && x>=0)
                    {
                        Installation work(info.getaddress());
                        float p3 = work.Installplant(x);
                        info.addmoney(p3);
                    }    
                    else 
                    {
                        cout << "Invalid worker ID!" << endl;
                    }
                    system("pause");
                    system("cls");
                }
                else if(ch==5)
                {
                    int y;
                    cout << endl;
                    W.displayWorkers();
                    cout << endl << "Enter valid worker ID: ";
                    cin >> y;
                    int z = W.getcount();
                    if (y<z && y>=0)
                    {
                        Appointment apt(info.getaddress());
                        float p4 = apt.BookAppointment(y);
                        info.addmoney(p4);
                    }
                    else 
                    {
                        cout << "Invalid worker ID!" << endl;
                    }    
                    system("pause");
                    system("cls");
                }
                else if(ch==6)
                {
                    cout << endl;
                    info.printInfo();	  
                    system("pause");
                    system("cls");
                }
                else if(ch==0)
                {
                    cout << "Going back...." << endl;
                    system("pause");
                    system("cls");
                }
                else {
                    cout << endl << "Invalid option!" << endl;
                }
            } while(ch!=0);
        break;
        
        case 0:
            cout << endl << "Exiting greenhouse...." << endl;
            system("cls");
        
    }
    }while(option==1 || option==2);

    //Filing part for Workers
        fstream fptr;
        Workers w;
        int id=0,I=0;
        string wname,Number;
        char gender,choice;
        fptr.open("Workers.txt",ios::out);
        fptr<<"WorkerID          Name          Number                  Gender\n";
        fptr.close();
        do
        {
            gender=W.worker[I].getgender();
            wname=W.worker[I].getname();
            Number=W.worker[I].getnum();
            fptr.open("Workers.txt",ios::app);
          
            if(fptr.is_open())
            {
                fptr << id;
                fptr << "                 ";
                fptr << wname;
                fptr << "               ";
                fptr << Number;
                fptr << "                   ";
                fptr << gender<<"\n";
            }
            else
            {
                cout<<"Error in opening file";
            }

            fptr.close();
            id++;
            I++;
        }while(I<worker_count);

    //Plants filing
        fstream plptr;
        string pname,ptype;
        int pos=0,p_id=0;
        plptr.open("Plants.txt",ios::out);
        plptr<<"Index            Name                    Type\n";
        plptr.close();
        do
        {
            pname=G.plants[pos].getName();
            ptype=G.plants[pos].gettype();
            plptr.open("Plants.txt",ios::app);
            if(plptr.is_open())
            {
                plptr<<p_id;
                plptr<<"               ";
                plptr<<pname;
                plptr<<"                ";
                plptr<<                 ptype<<"\n";
            }
            else
            {
                cout<<"Error in opening file";
            }
            
            plptr.close();
            p_id++;
            pos++;
        }while(pos<plant_counter);

    return 0;
} 
