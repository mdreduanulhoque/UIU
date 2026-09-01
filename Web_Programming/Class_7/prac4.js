

let total_price = 0
let items = ""

document.getElementById("submit-button").addEventListener("click", function () {
  let name = document.getElementById("name-input").value;

  let quantity = Number(document.getElementById("quantity-input").value);

  let unit_price = Number(document.getElementById("price-input").value);

 total_price = quantity * unit_price

 items += `item name: ${name} | price: ${unit_price} | quantity: ${quantity} \n`
 
 let discount = total_price*0.2

  if(total_price > 1000){
    total_price = total_price - (0.2 * total_price)
    document.getElementById("show-output").innerHTML = `<b>Your total cost is ${total_price}</b><br>You got discount: ${discount} Taka<br>Selected item: ${items}`
  }else{
    document.getElementById("show-output").innerHTML = `<b>Your total cost is ${total_price}</b><br>Selected item: ${items}`
  }


});
