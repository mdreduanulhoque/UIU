const express = require("express")
const router = express.Router();
const {getContacts, createContact, getContact, updateCotact, deleteCotact} = require("../controllers/contactController")

// Get all contacts
router.route("/").get(getContacts);

// Get contact by id
router.route("/:id").get(getContact);

// Create new contact
router.route("/").post(createContact);

// Update contact
router.route("/:id").put(updateCotact);

// Delete contact
router.route("/:id").delete(deleteCotact);


module.exports = router;