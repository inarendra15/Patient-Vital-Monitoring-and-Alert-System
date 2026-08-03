# 🏥 Patient Vital Monitoring and Alert System (PVM&AS)

> A modular, object-oriented Patient Vital Monitoring and Alert System developed in **C++17** that monitors patient health, detects abnormal vital signs, generates emergency alerts, prioritizes critical patients, performs health analytics, and produces professional patient reports with persistent storage.

---

## 📌 Project Overview

The **Patient Vital Monitoring and Alert System (PVM&AS)** is a console-based healthcare management application that simulates how hospitals monitor patient health in real time.

The system enables healthcare staff to:

- Register and manage patients
- Record patient vital signs
- Detect abnormal conditions automatically
- Generate emergency alerts
- Prioritize critical patients
- Perform hospital-wide analytics
- Produce patient health reports
- Persist all data using text files

The project is designed using **Object-Oriented Programming (OOP)** principles and demonstrates practical usage of STL containers, algorithms, file handling, modular software design, and healthcare workflow simulation.

---

# 🚀 Features

## 👤 Patient Management

- Register new patients
- Automatic Patient ID generation
- Search patients in O(1) average time using Hash Map
- Display all registered patients

---

## ❤️ Vital Sign Monitoring

Record:

- Heart Rate
- SpO₂
- Body Temperature
- Systolic Blood Pressure
- Diastolic Blood Pressure
- Respiratory Rate
- Timestamp

---

## 🚨 Intelligent Alert System

Automatically detects:

- High Heart Rate
- Low Heart Rate
- Low SpO₂
- Fever
- Hypothermia
- High Blood Pressure
- Low Blood Pressure
- Abnormal Respiratory Rate

Alerts are stored permanently.

---

## 📊 Analytics Dashboard

Provides:

- Average Heart Rate
- Average SpO₂
- Average Temperature
- Average Blood Pressure
- Average Respiratory Rate
- Highest Heart Rate
- Lowest SpO₂

---

## ❤️ Patient Health Scoring

Each patient receives:

- Health Score (0–100)
- Health Status

Possible Status:

- Healthy
- Stable
- Observation
- High Risk
- Critical

---

## ⚠ Critical Patient Priority Queue

Automatically ranks patients based on:

- Health Score
- Risk Level

Uses **priority_queue** for efficient emergency prioritization.

---

## 🚑 Emergency Response System

Automatically classifies:

- GREEN
- YELLOW
- ORANGE
- RED

Generates recommended emergency actions.

---

## 📈 Emergency Statistics

Displays:

- Total Emergency Reports
- GREEN cases
- YELLOW cases
- ORANGE cases
- RED cases
- Critical Percentage
- Most Frequent Emergency Level

---

## 📄 Patient Report Generator

Automatically creates professional reports including:

- Patient Information
- Latest Vital Signs
- Health Score
- Health Status
- Timestamp

Reports are stored inside:

```
reports/
```

---

## 💾 Persistent Storage

Stores:

- Patients
- Vital Signs
- Alerts
- Emergency Reports

Automatically loads all saved data when the application starts.

---

# 🛠 Technologies Used

| Technology | Purpose |
|------------|---------|
| C++17 | Core Programming Language |
| STL | Data Structures |
| Object-Oriented Programming | Software Architecture |
| File Handling | Persistent Storage |
| Hash Map | Fast Patient Search |
| Priority Queue | Critical Patient Ranking |
| Vector | Dynamic Data Storage |
| Modular Design | Maintainability |

---

# 🧠 Object-Oriented Concepts

The project demonstrates:

- Encapsulation
- Abstraction
- Composition
- Modular Design
- Class Collaboration
- Const Correctness
- Separation of Concerns

---

# 📚 Data Structures Used

| Data Structure | Purpose |
|---------------|---------|
| vector | Store Patients |
| vector | Store Vital History |
| unordered_map | Patient Index |
| unordered_map | Vital History Index |
| priority_queue | Critical Patient Queue |

---

# ⚡ Algorithms Used

- Health Score Calculation
- Threshold-Based Alert Detection
- Priority Queue Ranking
- Emergency Classification
- Hospital Analytics
- Hash-based Patient Lookup

---

# 📂 Project Structure

```text
PVM&AS/
│
├── data/
│   ├── patients.txt
│   ├── vitals.txt
│   ├── alerts.txt
│   └── emergency.txt
│
├── reports/
│
├── include/
│
├── src/
│
├── README.md
│
└── .gitignore
```

---

# 📸 Project Screenshots

*(To be added)*

- Main Menu
- Analytics Dashboard
- Priority Queue
- Emergency Report
- Patient Report
- Generated Files

---

# 📐 Architecture Diagram

*(Coming in next section)*

---

# 🔄 Workflow Diagram

*(Coming in next section)*

---

# ▶ How to Compile

Using g++:

```bash
g++ -std=c++17 src/main.cpp \
src/Patient.cpp \
src/PatientManager.cpp \
src/VitalSigns.cpp \
src/VitalManager.cpp \
src/ThresholdConfig.cpp \
src/Alert.cpp \
src/AlertEngine.cpp \
src/FileManager.cpp \
src/AnalyticsManager.cpp \
src/PriorityManager.cpp \
src/EmergencyManager.cpp \
src/EmergencyStatistics.cpp \
src/ReportManager.cpp \
-o patient_monitor
```

---

# ▶ Run

Windows

```bash
.\patient_monitor.exe
```

Linux/macOS

```bash
./patient_monitor
```

---

# 📈 Future Improvements

Possible future enhancements include:

- GUI using Qt
- SQLite/MySQL integration
- Multi-user authentication
- Doctor dashboard
- Nurse dashboard
- REST API integration
- Cloud storage
- Real-time monitoring
- Email/SMS alerts
- PDF report generation

---

# 👨‍💻 Author

**Narendra**

M.Tech Computer Science & Engineering

National Institute of Technology Delhi

---

# ⭐ If you found this project useful

Please consider giving it a ⭐ on GitHub.