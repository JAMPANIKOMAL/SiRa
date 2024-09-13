import 'dart:async';
import 'dart:math';
import 'package:flutter/material.dart';
//import 'dart:async';

void main() {
  runApp(MedifyApp());
}

class MedifyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(primarySwatch: Colors.blue),
      home: SplashScreen(), // SplashScreen is the initial page
    );
  }
}

class SplashScreen extends StatefulWidget {
  @override
  _SplashScreenState createState() => _SplashScreenState();
}

class _SplashScreenState extends State<SplashScreen> {
  @override
  void initState() {
    super.initState();
    // Delay to show the splash screen for 3 seconds
    Timer(Duration(seconds: 4), () {
      Navigator.of(context).pushReplacement(
          MaterialPageRoute(builder: (context) => HomePage()));
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.teal[300], // Customize this color as you like
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            // App logo (replace with your image)
            Icon(Icons.local_hospital, size: 100, color: Colors.white),
            SizedBox(height: 20),
            Text(
              "Medify",
              style: TextStyle(
                  fontSize: 30, color: Colors.white, fontWeight: FontWeight.bold),
            ),
          ],
        ),
      ),
    );
  }
}

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Medify - Keeps Every Record'),
        backgroundColor: Colors.teal,
        elevation: 4,
        foregroundColor: Colors.black,
      ),
      body: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(
            colors: [Colors.teal[300]!, Colors.teal[600]!],
            begin: Alignment.topLeft,
            end: Alignment.bottomRight,
          ),
        ),
        child: Center(
          child: Container(
            padding: EdgeInsets.all(24),
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(16),
              boxShadow: [
                BoxShadow(
                  color: Colors.black.withOpacity(0.2),
                  spreadRadius: 4,
                  blurRadius: 10,
                  offset: Offset(0, 3),
                ),
              ],
            ),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  'Select a Role',
                  style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: 24,
                    color: Colors.teal[700],
                  ),
                ),
                SizedBox(height: 20),
                _buildRoleButton(
                  context,
                  'Patient',
                  Icons.person,
                  PatientLogin(),
                ),
                SizedBox(height: 20),
                _buildRoleButton(
                  context,
                  'Doctor',
                  Icons.medical_services,
                  DoctorLoginPage(),
                ),
                SizedBox(height: 20),
                _buildRoleButton(
                  context,
                  'Hospital',
                  Icons.local_hospital,
                  HospitalAdminLogin(),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  ElevatedButton _buildRoleButton(
      BuildContext context, String label, IconData icon, Widget page) {
    return ElevatedButton.icon(
      onPressed: () {
        Navigator.push(
          context,
          MaterialPageRoute(builder: (context) => page),
        );
      },
      icon: Icon(icon, size: 18),
      label: Text(label),
      style: ElevatedButton.styleFrom(
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(12),
        ),
        padding: EdgeInsets.symmetric(vertical: 12, horizontal: 24),
        textStyle: TextStyle(fontSize: 18),
      ),
    );
  }
}

class PatientLogin extends StatefulWidget {
  @override
  _PatientLoginState createState() => _PatientLoginState();
}

class _PatientLoginState extends State<PatientLogin> {
  final TextEditingController patientIdController = TextEditingController();
  final TextEditingController passwordController = TextEditingController();

  // Define valid user credentials
  final Map<String, String> validCredentials = {
    'user123': 'password123',
    'user456': 'password456',
  };

  void _login() {
    final String userId = patientIdController.text;
    final String password = passwordController.text;

    if (validCredentials.containsKey(userId) && validCredentials[userId] == password) {
      Navigator.push(
        context,
        MaterialPageRoute(builder: (context) => PatientHomePage()),
      );
    } else {
      // Show an error message if the credentials are incorrect
      showDialog(
        context: context,
        builder: (BuildContext context) {
          return AlertDialog(
            title: Text('Login Failed'),
            content: Text('Invalid User ID or Password. Please try again.'),
            actions: <Widget>[
              TextButton(
                child: Text('OK'),
                onPressed: () {
                  Navigator.of(context).pop();
                },
              ),
            ],
          );
        },
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Patient Login'),
        backgroundColor: Colors.teal, // Customize AppBar color
      ),
      body: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(
            colors: [Colors.teal[200]!, Colors.teal[400]!],
            begin: Alignment.topLeft,
            end: Alignment.bottomRight,
          ),
        ),
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            children: <Widget>[
              TextField(
                style: TextStyle(color: Colors.black),
                controller: patientIdController,
                decoration: InputDecoration(
                  labelText: 'User ID',
                  border: OutlineInputBorder(),
                  fillColor: Colors.white, // Set input box background color
                  filled: true, // Enable background color
                ),
              ),
              SizedBox(height: 16), // Add space between text fields
              TextField(
                style: TextStyle(color: Colors.black),
                controller: passwordController,
                obscureText: true,
                decoration: InputDecoration(
                  labelText: 'Password',
                  border: OutlineInputBorder(), // Added border for consistency
                  fillColor: Colors.white, // Set input box background color
                  filled: true, // Enable background color
                ),
              ),
              SizedBox(height: 20),
              ElevatedButton(
                onPressed: _login,
                child: Text('Login'),
                style: ElevatedButton.styleFrom(
                  backgroundColor: Colors.white,
                  // Customize button color
                  padding: EdgeInsets.symmetric(horizontal: 24, vertical: 12),
                ),
              ),
              SizedBox(height: 20),
              TextButton(
                onPressed: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => SignupPage(userType: ''),
                    ),
                  );
                },
                child: Text('Don\'t have an account? Sign up'),
                style: TextButton.styleFrom(
                  foregroundColor: Colors.white, // Customize text color
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

class PatientHomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Patient Home Page'),
        backgroundColor: Colors.teal[800], // Darker shade for the AppBar
        elevation: 4, // Add elevation for a shadow effect
      ),
      body: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(
            colors: [Colors.teal[50]!, Colors.teal[300]!], // Adjusted gradient
            begin: Alignment.topLeft,
            end: Alignment.bottomRight,
          ),
        ),
        child: ListView(
          padding: EdgeInsets.all(16.0),
          children: [
            ListTile(
              leading: Icon(Icons.person, color: Colors.teal[700]), // Customize icon color
              title: Text('My Profile', style: TextStyle(color: Colors.teal[900])), // Customize text color
              onTap: () {
                Navigator.push(context,
                    MaterialPageRoute(builder: (context) => PatientProfile()));
                // Navigate to patient details page or perform patient profile logic
              },
            ),
            ListTile(
              leading: Icon(Icons.local_hospital, color: Colors.teal[700]), // Customize icon color
              title: Text('Nearby Hospital', style: TextStyle(color: Colors.teal[900])), // Customize text color
              onTap: () {
                Navigator.push(context,
                    MaterialPageRoute(builder: (context) => NearbyHospital()));
                // Navigate to patient details page or perform patient profile logic
              },
            ),
            ListTile(
              leading: Icon(Icons.local_pharmacy, color: Colors.teal[700]), // Customize icon color
              title: Text('Nearby Pharmacy', style: TextStyle(color: Colors.teal[900])), // Customize text color
              onTap: () {
                Navigator.push(context,
                    MaterialPageRoute(builder: (context) => NearbyPharmacy()));
                // Navigate to patient details page or perform patient profile logic
              },
            ),
            ListTile(
              leading: Icon(Icons.medical_services, color: Colors.teal[700]), // Customize icon color
              title: Text('Medicine', style: TextStyle(color: Colors.teal[900])), // Customize text color
              onTap: () {
                Navigator.push(context,
                    MaterialPageRoute(builder: (context) => NearbyMedicines()));
                // Navigate to patient details page or perform patient profile logic
              },
            ),
          ],
        ),
      ),
    );
  }
}

class PatientProfile extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('My Profile'),
        backgroundColor: Colors.teal,
      ),
      body: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(
            colors: [Colors.teal[50]!, Colors.teal[300]!],
            begin: Alignment.topLeft,
            end: Alignment.bottomRight,
          ),
        ),
        child: ListView(
          padding: EdgeInsets.all(16.0),
          children: <Widget>[
            ProfileItem(title: 'Name', value: 'DIYA SOLANKI'),
            SizedBox(height: 10),
            ProfileItem(title: 'Gender', value: 'Female'),
            SizedBox(height: 10),
            ProfileItem(title: 'Date of Birth', value: '01/01/2005'),
            SizedBox(height: 10),
            ProfileItem(title: 'Phone Number', value: '1234567890'),
            SizedBox(height: 10),
            ProfileItem(title: 'Email', value: 'diyas@gmail.com'),
            SizedBox(height: 10),
            ProfileItem(title: 'Address', value: 'Gandhinagar, Gujrat'),
            SizedBox(height: 10),
            ProfileItem(title: 'Marital Status', value: 'Unmarried'),
            SizedBox(height: 10),
            ProfileItem(title: 'Is patient younger than 18?', value: 'YES'),
            SizedBox(height: 10),
            ProfileItem(title: 'Emergency Contact Name', value: 'Tejas Patil'),
            SizedBox(height: 10),
            ProfileItem(title: 'Emergency Contact Number', value: '0987654321'),
            SizedBox(height: 10),
            ProfileItem(title: 'Family Doctor Name', value: 'Dr. Patel'),
            SizedBox(height: 10),
            ProfileItem(title: 'Family Doctor Phone', value: '1234567890'),
            SizedBox(height: 10),
            ProfileItem(title: 'Preferred Pharmacy', value: 'Apollo Pharmacy'),
            SizedBox(height: 10),
            ProfileItem(title: 'Preferred Pharmacy Phone', value: '0987654321'),
            SizedBox(height: 10),
            ProfileItem(title: 'Currently Taking Medication', value: 'No'),
            SizedBox(height: 10),
            ProfileItem(title: 'Allergic to Any Medicine', value: 'No'),
          ],
        ),
      ),
    );
  }
}

class NearbyHospital extends StatefulWidget {
  @override
  _NearbyHospitalState createState() => _NearbyHospitalState();
}

class _NearbyHospitalState extends State<NearbyHospital> {
  final List<String> _allHospitals = [
    'Mishika Multispeciality Hospital: 4th Floor, BALMUKUND SQUARE, Nehru Chokdi, Dahegam, Gujarat 382305',
    'Pratham Hospital: Third floor, Balmukund Complex, opp. Amin Society, near Nehru Chokdi, Darshan Society, GIDC, Dahegam, Gujarat 382305',
    'Mamta Multispeciality Hospital: 1st Floor Shiv Shakti Complex Opp Pashu Dawa Khana, below Matru Hospital, Dehgam-Rakhiyal, Road, Dahegam, Gujarat 382305',
    'Apollo Hospital International Limited Ahmedabad: Plot No, 1A, Gandhinagar - Ahmedabad Rd, GIDC Bhat, Estate, Ahmedabad, Gujarat 382428',
    'Sterling Hospitals - Gurukul Ahmedabad: Sterling Hospital Rd, near Maharaja Agrasen Vidhyalaya, nr. Nilmani Society, L.K Society, Nilmani Society, Memnagar, Ahmedabad, Gujarat 380052',
    'KD Hospital: Vaishnodevi Circle, Sarkhej - Gandhinagar Hwy, Ahmedabad, Gujarat 382421',
    'Aashka Multispeciality Hospital: Gandhinagar Bypass Rd, Sargasan, Gandhinagar, Gujarat 382421',
    'SMVS Swaminarayan Hospital: Gandhinagar - Ahmedabad Rd, beside Swaminarayan Dham, Randesan, Gandhinagar, Gujarat 382007',
    'SCAI Superspeciality Hospitals: 001/002 Ground Floor, Corporate Unit, Siddhraj Z2, near SCAI Hospitals Circle, Kudasan, Gandhinagar, Gujarat 382421',
    'Shalby Multi-Specialty Hospitals, Surat: Nr. Navyug College, Rander Rd, Adajan, Surat, Gujarat 395009',
    'Sunshine Global Hospital: Dumas Rd, beside Big Bazar, Piplod, Surat, Gujarat 395007',
    'Bombay Multi Speciality Hospital: 4th Floor Atlanta Mall, Bhimrad-Althan Rd, Apcha Nagar, Bhimrad, Surat, Gujarat 395017',
    'Unity Multispeciality Hospital: Unity Hospital, Rajesh Tower Rd, near Hari Nagar Cross Road, opp. Suner Complex, Gotri, Vadodara, Gujarat 390021',
    'Venus Super Speciality Hospital: Off OP Road Opp. Akota Ward Office No 6, Vadodara, Gujarat 390020',
    'Vraj Hospital Pvt. Ltd.: First Floor, Yaksha Shree Complex, Guru Gobindsinhji Marg, opp. Mahakali Temple, near Kumkum Party Plot, TP 13, Chhani Jakatnaka, Vadodara, Gujarat 390002',
  ];

  List<String> _filteredHospitals = [];

  @override
  void initState() {
    super.initState();
    _filteredHospitals = _allHospitals;
  }

  void _filterHospitals(String query) {
    setState(() {
      _filteredHospitals = _allHospitals
          .where((hospital) => hospital.toLowerCase().contains(query.toLowerCase()))
          .toList();
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Nearby Hospitals'),
        backgroundColor: Colors.teal, // Teal background color for the AppBar
      ),
      body: Container(
        color: Colors.teal, // Background color
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: TextField(
                onChanged: _filterHospitals,
                style: TextStyle(color: Colors.black), // Black text color
                decoration: InputDecoration(
                  labelText: 'Search',
                  labelStyle: TextStyle(color: Colors.black), // Black label color
                  border: OutlineInputBorder(),
                  filled: true,
                  fillColor: Colors.white, // White background for the search bar
                ),
              ),
            ),
            Expanded(
              child: ListView.builder(
                itemCount: _filteredHospitals.length,
                itemBuilder: (context, index) {
                  return Container(
                    margin: EdgeInsets.all(8.0),
                    padding: EdgeInsets.all(16.0),
                    decoration: BoxDecoration(
                      color: Colors.white, // White box color
                      borderRadius: BorderRadius.circular(8.0),
                    ),
                    child: Text(
                      _filteredHospitals[index],
                      style: TextStyle(color: Colors.black), // Black text color
                    ),
                  );
                },
              ),
            ),
          ],
        ),
      ),
    );
  }
}

class NearbyPharmacy extends StatefulWidget {
  @override
  _NearbyPharmacyState createState() => _NearbyPharmacyState();
}

class _NearbyPharmacyState extends State<NearbyPharmacy> {
  final List<String> _allPharmacies = [
    'PharmEasy Medicine Point: 16 Shreenath Arcade Dehgam, Dahegam, Gujarat 382305',
    'Apollo Pharmacy: Plot no. 1555, GH Rd, near GH 2 Circle, Sector 6, Gandhinagar, Gujarat 382006',
    'Apollo Pharmacy: Shop No 12 & 13, Ground Floor, Kanam 2, near Reliance Chowkdi, Kudasan, Ahmedabad, Gujarat 382421',
    'Apollo Pharmacy: Mann Complex, 6, Anand Mahal Rd, Opposite Shree Ram Petrol Pump, Adajan, Surat, Gujarat 395009',
    'Medkart Pharmacy: Shop No 7, Om Complex, Vasna Rd, near Taksh Complex, Shivashraya Society, Tandalja, Vadodara, Gujarat 390015',
  ];

  List<String> _filteredPharmacies = [];

  @override
  void initState() {
    super.initState();
    _filteredPharmacies = _allPharmacies;
  }

  void _filterPharmacies(String query) {
    setState(() {
      _filteredPharmacies = _allPharmacies
          .where((pharmacy) => pharmacy.toLowerCase().contains(query.toLowerCase()))
          .toList();
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Nearby Pharmacies'),
        backgroundColor: Colors.teal,
      ),
      body: Container(
        color: Colors.teal, // Background color
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: TextField(
                onChanged: _filterPharmacies,
                style: TextStyle(color: Colors.black), // Black text color in the search box
                decoration: InputDecoration(
                  labelText: 'Search',
                  labelStyle: TextStyle(color: Colors.black), // Black label color
                  border: OutlineInputBorder(),
                  filled: true,
                  fillColor: Colors.white, // White background for the search box
                ),
              ),
            ),
            Expanded(
              child: ListView.builder(
                itemCount: _filteredPharmacies.length,
                itemBuilder: (context, index) {
                  return Container(
                    margin: EdgeInsets.all(8.0),
                  