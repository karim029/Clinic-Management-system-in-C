# Clinic Management System in C using LinkedList

This Clinic Management System is a console-based program implemented in C to manage patient records and appointments. It utilizes linked lists for storing patient records and reservation slots. Below are more detailed explanations of the features and functions implemented in the code:

## Features and Functions

### 1. **Patient Records:**
   - **Create New Patient Record:**
     - Function: `patient_record collect_patient_data(void)`
     - Usage: Call this function to collect information for a new patient record. It prompts the user for patient name, ID, age, and gender. It ensures that the entered ID is unique.
     
   - **Display All Patient Records:**
     - Function: `void display_all_patients(void)`
     - Usage: Call this function to display a list of all patient records. It iterates through the linked list of patients and prints their information.

### 2. **Patient Record Modification:**
   - **Edit Patient Records:**
     - Function: `void edit_patient_record(patients* edited_patient)`
     - Usage: Call this function, passing a pointer to the patient record you want to edit. It prompts the user to enter updated information for the patient.

### 3. **Reservations:**
   - **View Available Slots:**
     - Function: `void print_available_slots(slot_list* s)`
     - Usage: Call this function, passing a pointer to the slot list. It prints a list of available appointment slots with their IDs, start times, and end times.

   - **Reserve a Slot:**
     - Function: `void reserve_slot(slot_list* s)`
     - Usage: Call this function, passing a pointer to the slot list. It prompts the user for their ID and the desired slot ID to make a reservation.

   - **Cancel Reservation:**
     - Function: `void cancel_reservation(slot_list* s)`
     - Usage: Call this function, passing a pointer to the slot list. It prompts the user for their ID and cancels the reservation for the corresponding slot.

### 4. **User Modes:**
   - **Admin Mode:**
     - Function: `void admin_mode(void)`
     - Usage: This function contains the logic for the admin mode. It prompts the user for a password and allows administrators to perform various actions, such as creating patient records, editing records, and managing reservations.

   - **User Mode:**
     - Function: `void user_mode(void)`
     - Usage: This function contains the logic for the user mode. Patients can view their own records and today's reservations.

### 5. **Initialization and Memory Management:**
   - **Initialize Slots:**
     - Function: `void init_slots(slot_list* s)`
     - Usage: Call this function to initialize the slot list with predefined appointment slots.

   - **Create New Patient Node:**
     - Function: `patients* create_new_patient(patient_record new_patient)`
     - Usage: Call this function, passing a new patient record. It creates a new node for the patient linked list.

   - **Add Patient to List:**
     - Function: `void add_patient_to_list(patients* patient_created)`
     - Usage: Call this function, passing a pointer to the new patient node. It adds the patient to the linked list of patients.

   - **Search for Patient:**
     - Function: `patients* search_for_patient(u32 id)`
     - Usage: Call this function, passing a patient ID. It searches for a patient with the given ID in the linked list and returns a pointer to the patient node.

### 6. **Display Information:**
   - **Print Today's Reservations:**
     - Function: `void print_today_reservations(slot_list* s)`
     - Usage: Call this function, passing a pointer to the slot list. It prints today's reservations, including slot information and patient details.

### 7. **User Interface and Control Flow:**
   - **Main Function:**
     - Function: `void main(void)`
     - Usage: The main function drives the overall control flow of the program. It presents options for admin and user modes and handles user interactions.

## Usage

1. **Compile the Code:**
   - Use a C compiler to compile the `main.c` file.
   - Example using GCC: `gcc main.c -o clinic_management_system`

2. **Run the Executable:**
   - Execute the compiled binary: `./clinic_management_system`

3. **Follow On-screen Instructions:**
   - Choose between Admin and User modes.
   - Enter the password for Admin mode.
   - Interact with the system as per the displayed menu options.

## Notes

- Feel free to use and modify the code to meet specific requirements.
- If you encounter any issues or have suggestions for improvement, consider submitting a pull request.
- Happy coding!