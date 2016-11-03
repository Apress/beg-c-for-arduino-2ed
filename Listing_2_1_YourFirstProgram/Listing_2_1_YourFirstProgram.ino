/* Listing 2-1 . The Source Code for Your First Program  */
void setup() 
{                       // Start of setup() function body             
 
 Serial.begin(9600);  // Step 1, Initialization

  // Step 2, Input (the letters between the quotes)
  // Step 3. Process - Serial object formats data for display 
  // Step 4. Output - Display the message on the monitor
  Serial.println("This is my first Arduino program!");
}                       // End of setup() function body             

 
void loop() 
{                       // Start of loop() function body             
}                       // End of loop() function body  
