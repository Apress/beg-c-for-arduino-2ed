/*  Listing 2-2. The Source Code for Your First Program, as Modified */
void setup() 
{                       // Start of setup() function body             
 
 Serial.begin(9600);  // Step 1, Initialization

  // Step 2, Input (the letters between the quotes)casll
  // Step 3. Process – Serial object formats data for display 
  // Step 4. Output – Display the message on the monitor
  

}                       // End of setup() function body             
 

void loop() 
{                       // Start of loop() function body 
Serial.println("This is my first Arduino Program!");
}                       // End of loop() function body   

