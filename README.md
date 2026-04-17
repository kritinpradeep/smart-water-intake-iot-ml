# Smart Water Intake Reminder (IoT + ML)

## 📌 Overview
This project is an IoT-based smart hydration system that monitors water intake and reminds users to drink water using adaptive machine learning predictions.

## 🚀 Features
- Real-time water level monitoring using ultrasonic sensor  
- NodeMCU ESP8266 for data collection  
- Machine Learning model for predicting drinking patterns  
- Adaptive reminder system (buzzer alerts)  
- Data visualization of water consumption  

## 🛠️ Tech Stack
- Hardware: NodeMCU ESP8266, Ultrasonic Sensor  
- Software: Arduino IDE, Python  
- Libraries: scikit-learn, pandas, matplotlib  

## ⚙️ Working
- Sensor detects water level  
- Data sent to Python via serial communication  
- ML model predicts next drinking time  
- Buzzer alerts user based on inactivity  

## 📊 Results
- ~95% accuracy in classification of water levels  
- Real-time prediction within 1 second  

## ▶️ How to Run
1. Upload code to NodeMCU  
2. Connect sensor and hardware  
3. Run Python script for ML model  
4. Monitor output and alerts  

## 📌 Future Improvements
- Mobile app integration  
- Cloud data storage  
- Advanced ML models (LSTM)  
