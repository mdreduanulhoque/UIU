
let total_attempt = 0;

document.getElementById("check-strength").addEventListener("click", function (){
    pass = document.getElementById("pass-input").value;
    total_attempt++;

    let point = 0;

    if(pass.length < 6){
        document.getElementById("extra-feedback").innerHTML = "Minimum 6 Characters Required";
    }

    if(pass.length >= 6){
        point += Math.round((pass.length/2)*10)
    }
    
    is_capital_present = 0;
    for(let i = 0; i < pass.length; i++){
        if(pass[i] >= "A" && pass[i] <= "Z"){
            is_capital_present = 1;
            break;
        }
    }
    if(is_capital_present){
        point += 15;
    }

    is_lowercase_present = 0;
    for(let i = 0; i < pass.length; i++){
        if(pass[i] >= "a" && pass[i] <= "z"){
            is_lowercase_present = 1;
            break;
        }
    }
    if(is_lowercase_present){
        point += 15;
    }

    is_number_present = 0;
    for(let i = 0; i < pass.length; i++){
        if(pass[i] >= "0" && pass[i] <= "9"){
            is_number_present = 1;
            break;
        }
    }
    if(is_number_present){
        point += 20;
    }

    is_specialcharacter_present = 0;
    for(let i = 0; i < pass.length; i++){
        if(pass[i] == "!" || pass[i] == "@" || pass[i] == "#" || pass[i] == "$" || pass[i] == "%" || pass[i] == "^" || pass[i] == "&" || pass[i] == "*"){
            is_specialcharacter_present = 1;
            break;
        }
    }
    if(is_specialcharacter_present){
        point += 25;
    }


    if(point >= 0 && point <= 30){
        document.getElementById("feedback").innerHTML = "Very Weak";
    }else if(point >= 31 && point <= 50){
        document.getElementById("feedback").innerHTML = "Weak";
    }else if(point >= 51 && point <= 70){
        document.getElementById("feedback").innerHTML = "Medium";
    }else if(point >= 71 && point <= 90){
        document.getElementById("feedback").innerHTML = "Strong";
    }else if(point >= 91 && point <= 100){
        document.getElementById("feedback").innerHTML = "Very Strong";
    }else if(point > 100){
        document.getElementById("feedback").innerHTML = "Perfect Password";
    }

    if(total_attempt > 8 && point <= 70){
        document.getElementById("extra-feedback").innerHTML = "Need Practice";
    }
});