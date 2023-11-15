#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include <string.h>

typedef struct {
	u32 slot_id;
	u8 start_time[10];
	u8 end_time[10];

}slot;

typedef struct {
		
	u8 patient_name[100];
	u32 patient_id;
	u32 patient_age;
	u8 patient_gender[100];
	u32 slot_id;
	
	
	
}patient_record;

typedef struct patient_list patients;

struct patient_list {
	patient_record data;
	patients* next;
	patients* prev;
};

typedef struct {
	slot slots[5];
	patients* reservations[5];
}slot_list;

patients* head = NULL;
patients* tail = NULL;
slot_list slotss;

void init_slots(slot_list* s) {
	
    s->slots[0].slot_id = 1;
    strcpy(s->slots[0].start_time, "2:00pm");
    strcpy(s->slots[0].end_time, "2:30pm");
    s->slots[1].slot_id = 2;
    strcpy(s->slots[1].start_time, "2:30pm");
    strcpy(s->slots[1].end_time, "3:00pm");
    s->slots[2].slot_id = 3;
    strcpy(s->slots[2].start_time, "3:00pm");
    strcpy(s->slots[2].end_time, "3:30pm");
    s->slots[3].slot_id = 4;
    strcpy(s->slots[3].start_time, "4:00pm");
    strcpy(s->slots[3].end_time, "4:30pm");
    s->slots[4].slot_id = 5;
    strcpy(s->slots[4].start_time, "4:30pm");
    strcpy(s->slots[4].end_time, "5:00pm");
	
    for (int i = 0; i < 5; i++) {
        s->reservations[i] = NULL;
    }
	
}


patients* create_new_patient(patient_record new_patient){
	
	patients* new_node  = (patients*)malloc(sizeof(patients));
	new_node -> data = new_patient;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	new_node->data.slot_id = 0;
	
	return new_node;
	
}

void add_patient_to_list (patients* patient_created){
	if(head == NULL){
		head = tail = patient_created;
	}else {
		tail -> next = patient_created;
		patient_created -> prev = tail;
		tail = patient_created;
	}
	
}


patients* search_for_patient(u32 id){
	patients* temp = head;
	while(temp){
		if(temp -> data.patient_id == id){
			return temp;
		}else{
			temp = temp -> next;
		}
		
	}
	
	return NULL;
}

void edit_patient_record(patients* edited_patient){
	
	printf("enter patient name: ");
	scanf(" %[^\n]s",&edited_patient->data.patient_name);
	printf("\n");
	printf("enter patient id: ");
	scanf("%d",&edited_patient->data.patient_id);
	printf("\n");
	printf("enter patient age: ");
	scanf("%d",&edited_patient->data.patient_age);
	printf("\n");
	printf("enter patient gender: ");
	scanf(" %[^\n]s",&edited_patient->data.patient_gender);
	printf("\n");
	
	
}

patient_record collect_patient_data(void){
    patient_record new_patient;
    patients* p_id;
    u32 id;
    
    printf("enter patient name: ");
    scanf(" %[^\n]s", &new_patient.patient_name);
    printf("\n");

    do {
        printf("enter patient id: ");
        scanf("%d", &new_patient.patient_id);

        p_id = search_for_patient(new_patient.patient_id);
        if (p_id != NULL) {
            printf("ID already exists, please enter a different ID.\n");
        }
    } while (p_id != NULL);

    printf("\n");
    printf("enter patient age: ");
    scanf("%d", &new_patient.patient_age);
    printf("\n");
    printf("enter patient gender: ");
    scanf(" %[^\n]s", &new_patient.patient_gender);
    printf("\n");
    printf("patient created and added to the list successfully!\n");

    return new_patient;
}
	
	


void display_all_patients(void){
	patients* temp = head;
	u8 i = 0;
	while(temp){
		printf("patient list: ");
		printf("\n");
		printf("------PATIENT (%d):------\n",i+1);
		printf("Patient name: %s",temp->data.patient_name);
		printf("\n");
		printf("student ID: %d",temp->data.patient_id);
		printf("\n");
		printf("Gender: %s",temp->data.patient_gender);
		printf("\n");
		printf("Age: %d",temp->data.patient_age);
		printf("\n");
		temp = temp -> next;
		i++;
	}
	if(head == NULL){
		printf("the List is empty\n");
	}
}

void print_available_slots(slot_list* s){
	printf("------AVAILABLE-SLOTS------:\n");
	for(u8 i = 0; i< 5; i++){
		
		if(s->reservations[i]==NULL){
			printf("slot: %d: %s - %s\n",s->slots[i].slot_id,s->slots[i].start_time, s->slots[i].end_time);
		}
		
	}
	
}
void print_today_reservations(slot_list* s){
	printf("------TODAY-RESERVATIONS------\n");
	printf("\n");
	
	
	for(u8 i =0; i<5;i++){
		
		if(s->reservations[i]!=NULL){
			printf("slot: %d: %s - %s Reserved By Patient: %s -- ID: %d \n",s->slots[i].slot_id,s->slots[i].start_time,s->slots[i].end_time,s->reservations[i]->data.patient_name,s->reservations[i]->data.patient_id);
		}
	}
	
}



void reserve_slot(slot_list* s){
	
	u32 patient_id, slot_id;
	patients* temp = head;
	
	printf("enter patient ID:\n");
	scanf("%d",&patient_id);
	
	 while (temp != NULL) {
        if (temp->data.patient_id == patient_id) {
			if(temp->data.slot_id != 0){
				printf("Patient already has a reservation.\n");
				return;
			}
            break;
        }
        temp = temp->next;
    }
	if(temp == NULL){
		printf("patient not found !\n");
		return;
	}
	printf("enter slot id to reserve: ");
	scanf("%d",&slot_id);
	
	if(slot_id< 1 || slot_id >5){
		printf("invalid slot ID:\n");
		return;
	}
	
	if (s->reservations[slot_id-1] != NULL) {
        printf("\nSlot already reserved!\n");
        return;
    }
    else {
        s->reservations[slot_id-1] = temp;
        temp->data.slot_id = slot_id;
        printf("\nSlot reserved successfully!\n");
		
    }
	
}

void cancel_reservation (slot_list* s){
	u32 patient_id;
	printf("enter patient ID: ");
	scanf("%d",&patient_id);
	
	patients* patient_node = search_for_patient(patient_id);
	
	if(patient_node == NULL){
		printf("no reservations found for patient ID: %d\n",patient_id);
		return;
	}
	
	u32 slot_id = patient_node ->data.slot_id;
	s->reservations[slot_id-1] = NULL;
	
	printf("reservation deleted for patient,\n");
	
}

void main(void){
	patient_record new_patient;
	patients* new_node;
	
	u32 id;
	u32 user_input;
	u32 user_Attemps=0;
	u32 admin = 0;
	u32 max_pass_Attemps = 3;
	u32 max_length = 4;
	u32 password[4] = {1,2,3,4};
	u32 input_password[4];
	if(head ==NULL){
	init_slots(&slotss);
	}
	printf("\n");
	printf("\\---------WELCOME-TO-CLINIC-MANAGEMENT-SYSTEM--------\\\n");
	printf("\n");
	printf("for ADMIN mode press 0:\n");
	printf("for USER mode press 1:\n");
	printf("\\----------------------------------------------------\\");
	printf("\n");
	scanf("%d",&user_input);
	
	switch(user_input){
		
		case 0:
			printf("please enter the password\n");
			while(user_Attemps < max_pass_Attemps){
				printf("Attempt %d: \n", user_Attemps+1);
				for(u8 i = 0; i<max_length;i++){
					
					scanf("%1d",&input_password[i]);
				}
				u32 pmatch = 1;
				for(u8 i =0; i<max_length;i++){
					if(input_password[i]!=password[i]){
						pmatch = 0;
						break;
						
					}
				}
				if (pmatch){
					printf("Correct Password, Welcome\n");
					admin = 1;
					break;
				}else{
					printf("wrong password\n");
					user_Attemps++;
				}
				if(user_Attemps == max_pass_Attemps){
					printf("Maximum number of attemps reached!!\n");
				}
			}	
				
				if(admin){
					while(1){
					printf("\\----------CLINIC-MANAGEMENT-SYSTEM----------\\\n");
					printf("\n");
					printf("~~to create a patient record press 0: \n");
					printf("~~to edit a patient record press 1: \n");
					printf("~~to display all patients record press 2: \n");
					printf("~~to edit patient record press 3: \n");
					printf("~~to reserve a slot for patient press 4: \n");
					printf("~~ to delete patient reservation press 5: \n");
					printf("~~ to view available reservations press 6: \n");
					printf("~~ to exit admin mode press 7: \n");
					scanf("%d",&user_input);
					
					switch(user_input){
						
						case 0:
							new_patient = collect_patient_data();
							new_node = create_new_patient(new_patient);
							add_patient_to_list(new_node);
							
							printf("\n");
						break;
						
						case 1:
						
						break;

						case 2:
							
							display_all_patients();
						break;
						
						case 3:
							printf("Enter patient id to edit his record.\n");
							scanf("%d",&id);
							new_node = search_for_patient(id);
							if(new_node == NULL){
								printf("Patient not found !!\n");
							}else{
								
								edit_patient_record(new_node);
								printf("Patient record has been modified succesfully !!\n");
							}
						break;
						
						case 4:
							print_available_slots(&slotss);
							reserve_slot(&slotss);
						break;
						
						case 5:
							cancel_reservation(&slotss);
						break;
						
						case 6:
							print_available_slots(&slotss);
							//print_today_reservations(&slotss);
							
							
						break;
						
						case 7:
							main();
						break;
						
					}
					
				}
					
					
				}
			
		break;
		case 1:		
				while(1){
					printf("\n");
					printf("\\----------CLINIC-MANAGEMENT-SYSTEM----------\\\n");
					printf("\n");
					printf("~~to view patient record press 0: \n");
					printf("~~to view today's reservations press 1: \n");
					printf("~~ to exit user mode press 2: \n");
					scanf("%d",&user_input);
					
					switch(user_input){
						
						case 0:
						printf("enter patient ID: ");
						scanf("%d",&id);
						new_node = search_for_patient(id);
						if(new_node == NULL){
								printf("Patient not found...\n");
							}else{
								printf("patient name: %s\n",new_node->data.patient_name);
								printf("patient Age: %d\n",new_node->data.patient_age);
								printf("patient gender: %s\n",new_node->data.patient_gender);
							}
						break;
						
					case 1:
						print_today_reservations(&slotss);
					break;
					
					case 2:
						main();
					break;
					
					
					
					}
				}
			
		break;
		
		default:
			printf("wrong command...\n");
			printf("Exiting program...");
			exit(0);
		break;
	
	}

}
